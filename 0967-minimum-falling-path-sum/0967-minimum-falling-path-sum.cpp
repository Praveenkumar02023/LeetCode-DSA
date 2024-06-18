class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& mat,vector<vector<int>> &dp){

        if (j < 0 || j >= mat[0].size()) return 1e9;
        if(i == mat.size()-1) return mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = mat[i][j] + solve(i+1,j,mat,dp);
        int diagLeft = mat[i][j] + solve(i+1,j-1,mat,dp);
        int diagRight = mat[i][j] + solve(i+1,j+1,mat,dp);

        return dp[i][j] = min({down,diagLeft,diagRight});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
        // int res = 1e9;
        // // for(int i = 0 ; i < mat[0].size() ;i++){
        // //     int minn = solve(0,i,mat,dp);
        // //     res =  min(res,minn);
        // // }

        // return res;

        for(int i = 0 ; i < mat[0].size() ; i++){
            dp[mat.size()-1][i] = mat[mat.size()-1][i];
        }

        for(int i = mat.size()-2 ; i >= 0 ; i--){

            for(int j = mat[0].size()-1 ; j >= 0 ; j--){

                int up = 1e9,diagRight = 1e9 , diagLeft = 1e9;
                up = mat[i][j] + dp[i+1][j];
                if(j < mat[0].size()-1) diagRight = mat[i][j] + dp[i+1][j+1];
                if(j > 0) diagLeft = mat[i][j] + dp[i+1][j-1];

                dp[i][j] = min({up,diagLeft,diagRight});
            }
        }
        int res = 1e9;
        for(int i = 0 ; i < mat[0].size() ; i++){
            res = min(res,dp[0][i]);
        }

        return res;


    }
};