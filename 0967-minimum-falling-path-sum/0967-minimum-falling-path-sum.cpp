class Solution {
public: 
    int f(int i , int j , int n , vector<vector<int>>& mat , vector<vector<int>>&dp){

        if(j < 0 ||j >= n) return 1e9+7;
        if(i == n-1) return mat[i][j];
        if(dp[i][j] != -1e9+7) return dp[i][j];

        return dp[i][j] = mat[i][j] + min({f(i+1,j-1,n,mat,dp),f(i+1,j,n,mat,dp),f(i+1,j+1,n,mat,dp)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9+7));

        int ans = 1e9+7;

        for(int i = 0 ; i < n ; i++){

            ans = min(ans,f(0,i,n,matrix,dp));

        }

        return ans;
    }
};