class Solution {
public:

    int solve(int i , int target , vector<int>& coins,vector<vector<int>> & dp){
        if(i == 0){
            if(target % coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notPick = 0 + solve(i-1,target,coins,dp);
        int Pick = INT_MAX;
        if(coins[i] <= target) Pick = 1 + solve(i,target-coins[i],coins,dp);

        return dp[i][target] = min(Pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount + 1 , -1));
        
        // int res =  solve(n-1,amount,coins,dp);
        //tabulation

        // for(int target = 0 ; target <= amount ; target++){
        //     if(target % coins[0] == 0) dp[0][target] = target/coins[0];
        //     else dp[0][target] = 1e9;
        // }

        // for(int i = 1 ; i < n ; i++){

        //     for(int target = 0 ; target <= amount ; target++){

        //             int notPick = 0 + dp[i-1][target];
        //             int Pick = INT_MAX;
        //             if(coins[i] <= target) Pick = 1 + dp[i][target-coins[i]];

        //             dp[i][target] = min(Pick,notPick);                

        //     }
        // }


        //space optimised
        
        vector<int> prev(amount+1,0),cur(amount+1,0);

        for(int target = 0 ; target <= amount ; target++){
            if(target % coins[0] == 0) prev[target] = target/coins[0];
            else prev[target] = 1e9;
        }

        for(int i = 1 ; i < n ; i++){

            for(int target = 0 ; target <= amount ; target++){

                    int notPick = 0 + prev[target];
                    int Pick = 1e9;
                    if(coins[i] <= target) Pick = 1 + cur[target-coins[i]];

                    cur[target] = min(Pick,notPick);                

            }
            prev = cur;
        }

        if(prev[amount] == 1e9) return -1;
        
        return prev[amount];
    }
};