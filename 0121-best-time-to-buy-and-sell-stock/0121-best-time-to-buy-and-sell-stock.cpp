class Solution {
public:
    int f(int i , int n , vector<int>& nums,vector<int> &dp){

        if(i >= n) return 0 ;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int minPrice = 1e9+7;
       for(int j = 0 ; j < i ; j++){

            minPrice = min(minPrice , nums[j]);
            ans = max(ans, nums[j] - minPrice);
       }
        //notTake
        ans = max(ans,f(i+1,n,nums,dp));

        return dp[i] =  ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    //    vector<int> dp(n+1,-1);
    //     return f(0,n,prices,dp);
        int buy = prices[0];
        int diff = 0;
        for(int i = 1 ;  i < n ; i++ ){
            diff = max(diff,prices[i] - buy);
            if(prices[i] < buy){
                buy = prices[i];
            }
        }

        return diff;
    }
};