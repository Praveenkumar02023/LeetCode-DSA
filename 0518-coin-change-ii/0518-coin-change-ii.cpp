class Solution {
public:

    int solve(int i , vector<int>& coins , int target,vector<vector<int>>& dp){
        
        if(i == 0){
            return (target%coins[0] == 0);
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notPick = solve(i-1,coins,target,dp);
        int Pick = 0;
        if(coins[i] <= target) Pick = solve(i,coins,target-coins[i],dp);

        return dp[i][target] = (Pick + notPick);
    }
    int change(int amount, vector<int>& coins) {
    int n  = coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};