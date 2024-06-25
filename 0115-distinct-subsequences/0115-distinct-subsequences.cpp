class Solution {
public:
    // int solve(int i , int j , string s , string t, vector<vector<int>>& dp){

    //     if(j == 0) return 1;
    //     if(i == 0) return 0;

    //    if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i-1] == t[j-1]) return dp[i][j] =  solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);

    //     return    dp[i][j] =  solve(i-1,j,s,t,dp);

    // }

    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int n = s.size() , m = t.size(); 
        vector<int> cur(m+1,0);

        // return solve(n,m,s,t,dp);

       cur[0] = 1;
        

        for(int i = 1 ; i <= n ; i++){
            for(int j = m ; j >= 1 ; j--){
                if(s[i-1] == t[j-1] ) cur[j] = (cur[j-1]%mod + cur[j]%mod)%mod;
                else cur[j] = cur[j];
            }
         
        }
        return cur[m];
    }
};