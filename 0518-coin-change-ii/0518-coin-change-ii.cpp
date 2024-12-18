class Solution {
public:
    int f(int i , int money ,vector<int>& nums,vector<vector<int>>& dp){

        if(money == 0) return 1;
        if(i < 0) return 0;
        if(dp[i][money] != -1) return dp[i][money];

        int take = 0;
        if(money >= nums[i])
                take = f(i,money-nums[i],nums,dp);
        int skip = f(i-1,money,nums,dp);
        return dp[i][money] = (skip + take);

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }
};