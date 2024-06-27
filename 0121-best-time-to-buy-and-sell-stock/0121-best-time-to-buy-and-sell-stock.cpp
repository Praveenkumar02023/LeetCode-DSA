class Solution {
public:

    int solve(vector<int>& arr, int j,int Maxx,vector<int>&dp){
        if(j < 0) return 0;

        if(dp[j] != -1) return dp[j];

        int Profit = 0;
        if(arr[j] > Maxx) Maxx = arr[j];
        else{
            Profit = Maxx-arr[j];
        }

        int possProfit = solve(arr,j-1,Maxx,dp);

        return dp[j] = max(possProfit,Profit);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        return solve(prices,n-1,INT_MIN,dp);
    }
};