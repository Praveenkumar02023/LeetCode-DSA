class Solution {
public:

    int solve(int i , int j , string& s1 ,string & s2,vector<vector<int>> & dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1] ) return dp[i][j] =  1 + solve(i-1,j-1,s1,s2,dp);

        return dp[i][j] = max(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp));

    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1 , -1));
        string t = s;
        reverse(t.begin(),t.end());

        int len =  solve(s.size(),t.size(),s,t,dp);

        return s.size()-len;
    }
};