class Solution {
public:
    int solve(int i , int j, int m , int n , vector<vector<int>>& dp,vector<vector<int>>& arr){

        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int down = 0;
        int right = 0;

        if( i < m-1 && arr[i+1][j] != 1) down = solve(i+1,j,m,n,dp,arr);
        if(j < n-1 && arr[i][j+1] != 1) right = solve(i,j+1,m,n,dp,arr);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m+1,vector<int>(n+1 , -1));

        return solve(0,0,m,n,dp,obstacleGrid);
    }
};