class Solution {
public:
    int solve(int i , int j , string& s , string &t,vector<vector<int>> &dp){
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = 1 + solve(i-1,j-1,s,t,dp);

        return dp[i][j] = max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(),t.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      return  solve(n,n,s,t,dp);
    }
};