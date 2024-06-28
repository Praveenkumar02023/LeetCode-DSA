class Solution {
public:
    // int solve(int i, vector<int>& arr, bool buy, int k,
    //           vector<vector<vector<int>>>& dp) {
    //     if (k == 0 || i == arr.size())
    //         return 0;
    //     if (dp[i][k][buy] != -1)
    //         return dp[i][k][buy];

    //     int take = 0;
    //     if (buy) {
    //         return dp[i][k][buy] =
    //                    max((arr[i] + solve(i + 1, arr, false, k - 1,dp)),
    //                        solve(i + 1, arr, true, k,dp));
    //     } else {
    //         return dp[i][k][buy] = max((-arr[i] + solve(i + 1, arr, true,
    //         k,dp)),
    //                                    solve(i + 1, arr, false, k,dp));
    //     }
    // }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // return solve(0, arr, false, k, dp);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = k; j >= 1; j--) {
                for (int l = 0; l <= 1; l++) {

                    if (l == 1) {
                        dp[i][j][l] = max((arr[i] + dp[i + 1][j - 1][false]),
                                            dp[i + 1][j][true]);
                    } else {
                        dp[i][j][l] = max((-arr[i] + dp[i + 1][j][true]),
                                            dp[i + 1][j][false]);
                    }
                }
            }
        }

        return dp[0][k][0];
    }
};