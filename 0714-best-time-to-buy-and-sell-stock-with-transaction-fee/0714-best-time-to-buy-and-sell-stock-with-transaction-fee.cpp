class Solution {
public:
    int solve(int i, vector<int>& arr, int fee, bool buy,
              vector<vector<int>>& dp) {
        if (i == arr.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int take = 0;
        if (buy) {
            take = max((-arr[i] + solve(i + 1, arr, fee, false, dp)),
                       solve(i + 1, arr, fee, true, dp));
        } else {
            take = max((arr[i] - fee + solve(i + 1, arr, fee, true, dp)),
                       solve(i + 1, arr, fee, false, dp));
        }
        return dp[i][buy] = take;
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return solve(0,arr,fee,true,dp);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                if (j) {
                    dp[i][j] =
                        max((-arr[i] + solve(i + 1, arr, fee, false, dp)),
                            solve(i + 1, arr, fee, true, dp));
                } else {
                    dp[i][j] =
                        max((arr[i] - fee + solve(i + 1, arr, fee, true, dp)),
                            solve(i + 1, arr, fee, false, dp));
                }
            }
        }
        return dp[0][1];
    }
};