class Solution {
public:
// Memoization
    // int solve(int n , vector<int>& dp){
    //     if(n <= 1) return dp[n] =  1;

    //     if(dp[n] != -1) return dp[n];

    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    int climbStairs(int n) {
        if(n <= 3) return n;
        // Tabulation

        // vector<int> dp(n+1,-1);
        // dp[0] = 1,dp[1] = 1;

        // for(int i = 2 ; i <= n ; i++){
        //     dp[i] = dp[i-2]+dp[i-1];
        // }
        // return dp[n];    

        // Space Optimised

        int prev2 = 2, prev = 3;
        int curr = 0;
        for(int i = 3 ; i < n ; i++){
            curr = prev + prev2;
            prev2 = prev ;
            prev = curr;
        }

        return curr;
    }
};