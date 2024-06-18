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
        // vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
        // int res = 1e9;
        // // for(int i = 0 ; i < mat[0].size() ;i++){
        // //     int minn = solve(0,i,mat,dp);
        // //     res =  min(res,minn);
        // // }

        // return res;

        vector<int> prev(mat[0].size(),-1);
        for(int i = 0 ; i < mat[0].size() ; i++){
            prev[i] = mat[mat.size()-1][i];
        }

        for(int i = mat.size()-2 ; i >= 0 ; i--){
            vector<int> curr(mat[0].size(),0);
            for(int j = mat[0].size()-1 ; j >= 0 ; j--){

                int up = 1e9,diagRight = 1e9 , diagLeft = 1e9;
                up = mat[i][j] + prev[j];
                if(j < mat[0].size()-1) diagRight = mat[i][j] + prev[j+1];
                if(j > 0) diagLeft = mat[i][j] + prev[j-1];

                curr[j] = min({up,diagLeft,diagRight});
            }

            prev = curr;
        }
        int res = 1e9;
        for(int i = 0 ; i < mat[0].size() ; i++){
            res = min(res,prev[i]);
        }

        return res;


    }
};