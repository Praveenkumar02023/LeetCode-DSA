class Solution {
public:
    int helper(int i , int buy, vector<int>& prices , vector<int>&dp){

        if(i == prices.size()) return 0;
       

        if(prices[i] < buy){
            buy = prices[i];
        }

        return max(prices[i] - buy , helper(i+1,buy,prices,dp));

    }
   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int buy = prices[0];
        // int diff = 0;
        // for(int i = 1 ;  i < n ; i++ ){
        //     diff = max(diff,prices[i] - buy);
        //     if(prices[i] < buy){
        //         buy = prices[i];
        //     }
        // }

        // return diff;
       
        vector<int> dp(n+1-1);
        return helper(1 , prices[0] , prices,dp);
    }
};