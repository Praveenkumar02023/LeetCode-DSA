class Solution {
public:
    int solve(int i , vector<int>& arr , int fee  , bool buy,vector<vector<int>>& dp){
        if(i == arr.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int take = 0 ;
        if(buy){
            take = max((-arr[i] + solve(i+1,arr,fee,false,dp)),solve(i+1,arr,fee,true,dp));
        }else{
            take = max((arr[i] - fee + solve(i+1,arr,fee,true,dp)) , solve(i+1,arr,fee,false,dp));
            }
        return dp[i][buy]  = take;
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,arr,fee,true,dp);
    }
};