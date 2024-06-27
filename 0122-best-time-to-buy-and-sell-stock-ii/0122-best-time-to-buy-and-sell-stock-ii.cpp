class Solution {
public:
    int solve(int i , vector<int>& arr , bool buy,vector<vector<int>> & dp){
        if(i == arr.size() ) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int take = 0;
        if(buy){
            take  = max((arr[i] + solve(i+1,arr,false,dp)) ,  0 + solve(i+1,arr,true,dp));
        }else{
            take =  dp[i][buy] = max((-arr[i] + solve(i+1,arr,true,dp)) ,0 + solve(i+1,arr,false,dp));
        }

        return  dp[i][buy] = take;
    }
       

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(0,prices,false,dp);
    }
};