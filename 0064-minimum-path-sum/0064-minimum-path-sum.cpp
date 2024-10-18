class Solution {
public:
    int solve(int i , int j , int m , int n , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i >= m || j >= n) return 1e9+7;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] =  grid[i][j] + min( solve(i+1,j,m,n,grid,dp) ,solve(i,j+1,m,n,grid,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() , n = grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return solve(0,0,m,n,grid,dp);
    }
};