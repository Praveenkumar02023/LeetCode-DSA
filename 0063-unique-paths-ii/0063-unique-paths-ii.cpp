class Solution {
public:

    int solve(int i , int j ,vector<vector<int>>& grid,vector<vector<int>> &dp ){
        if(i == 0 && j == 0) return 1;

        if(i < 0 || j < 0 ) return 0;

        if(grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i-1,j,grid,dp);
        int left = solve(i,j-1,grid,dp);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};