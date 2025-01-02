class Solution {
public:
    int solve(int i , int j , vector<string>& words , string &target,vector<vector<int>>&dp,vector<vector<int>>& freq){
        if(i == target.size()) return 1;
        if(j == words[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j]; 

        long long take = (long long)freq[target[i]-'a'][j] * solve(i+1,j+1,words,target,dp,freq) % 1000000007;

        int notTake = solve(i,j+1,words,target,dp,freq);

        return dp[i][j] = (take + notTake)% 1000000007;
    }

    int numWays(vector<string>& words, string target) {
        
        int i = 0;
        int j = 0;
        int n = words[0].size();
        int m = target.size();

        vector<vector<int>> freq(26,vector<int>(n));


        for(int j  = 0; j < n ; j++){

            for(int i = 0 ; i < words.size() ; i++){

                freq[words[i][j] - 'a'][j]++;

            }

        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(i,j,words,target,dp,freq);
    }
};