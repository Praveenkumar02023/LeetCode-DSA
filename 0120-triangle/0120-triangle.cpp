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

    void tabulation(){
        
        // for(int j = 0 ; j < n ; j++ ){
        //     dp[n-1][j] = triangle[n-1][j];
        // }

        // for(int i = n-2 ; i >= 0 ; i--){
        //     for(int j = i ; j >= 0 ; j--){

        //         int up = triangle[i][j] + dp[i+1][j];

        //         int diag = triangle[i][j] + dp[i+1][j+1];

        //         dp[i][j] = min(up,diag);
        //     }
        // }

        // return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);

        for(int j = 0 ; j < n ; j++ ){
            prev[j] = triangle[n-1][j];
        }

        for(int i = n-2 ; i >= 0 ; i--){
            vector<int> curr(n,0);
            for(int j = i ; j >= 0 ; j--){

                int up = triangle[i][j] + prev[j];

                int diag = triangle[i][j] + prev[j+1];

                curr[j] = min(up,diag);
         
         
            }

            prev = curr;
        }
        
        return prev[0];

    }
};