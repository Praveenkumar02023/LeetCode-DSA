class Solution {
public:
    int solve(int i, int j ,int n, vector<vector<int>>& arr , vector<vector<int>>& dp){

        if(i >= n || j > i) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] =  arr[i][j] + min(solve(i+1,j+1,n,arr,dp) ,solve(i+1,j,n,arr,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(0,0,n,triangle,dp);
    }
};