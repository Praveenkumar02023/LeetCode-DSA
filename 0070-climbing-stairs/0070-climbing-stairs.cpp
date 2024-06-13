class Solution {
public:
// Memoization
    // int solve(int n , vector<int>& dp){
    //     if(n <= 1) return dp[n] =  1;

    //     if(dp[n] != -1) return dp[n];

    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // Tabulation

        dp[0] = 1,dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-2]+dp[i-1];
        }

        return dp[n];    
    }
};