class Solution {
public:
    int solve(int i, vector<int>& arr, bool buy, int k,
              vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == arr.size())
            return 0;
        if (dp[i][k][buy] != -1)
            return dp[i][k][buy];

        int take = 0;
        if (buy) {
            return dp[i][k][buy] =
                       max((arr[i] + solve(i + 1, arr, false, k - 1,dp)),
                           solve(i + 1, arr, true, k,dp));
        } else {
            return dp[i][k][buy] = max((-arr[i] + solve(i + 1, arr, true, k,dp)),
                                       solve(i + 1, arr, false, k,dp));
        }
    }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(0, arr, false, k, dp);
    }
};