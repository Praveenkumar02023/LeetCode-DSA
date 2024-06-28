class Solution {
public:
    int solve(int i , vector<int> & arr , int transaction,int buy,vector<vector<vector<int>>>& dp){
        if(transaction == 0) return 0;
        if(i == arr.size()) return 0;

        if(dp[i][transaction][buy] != -1) return dp[i][transaction][buy];

        int take = 0;
        if(buy){
            take = max((arr[i] + solve(i+1,arr,transaction-1,false,dp)),(solve(i+1,arr,transaction,true,dp)));
        }else{
            take = max((-arr[i] + solve(i+1,arr,transaction,true,dp)),(solve(i+1,arr,transaction,false,dp)));
        }

        return dp[i][transaction][buy] = take;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,prices,2,false,dp);
    }
};