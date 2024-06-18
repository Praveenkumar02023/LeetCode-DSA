class Solution {
public:
    int solve(int i , int j ,vector<vector<int>>& grid,vector<vector<int>> &dp ){
        if(i == grid.size()-1) return grid[i][j];

        if(i >= grid.size()) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int down = grid[i][j] + solve(i+1,j,grid,dp);
        int diag = grid[i][j] + solve(i+1,j+1,grid,dp);

        return dp[i][j] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
};