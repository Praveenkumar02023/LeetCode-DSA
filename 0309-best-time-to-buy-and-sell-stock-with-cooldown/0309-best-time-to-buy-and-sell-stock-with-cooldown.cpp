class Solution {
public:
    int solve(int i, vector<int>& arr, bool buy, bool coolDown,
              vector<vector<vector<int>>>& dp) {
        if (i == arr.size())
            return 0;

        if (dp[i][buy][coolDown] != -1)
            return dp[i][buy][coolDown];

        int take = 0;
        if (buy && coolDown) {
            take = dp[i][buy][coolDown] =
                       max((-arr[i] + solve(i + 1, arr, false, true, dp)),
                           solve(i + 1, arr, true, true, dp));
        } else if (buy == false) {
            take = dp[i][buy][coolDown] =
                       max((arr[i] + solve(i + 1, arr, true, false, dp)),
                           solve(i + 1, arr, false, true, dp));
        } else if (buy && coolDown == false) {
            take = dp[i][buy][coolDown] = solve(i + 1, arr, true, true, dp);
        }

        return take;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(0, arr, true, true, dp);
    }
};