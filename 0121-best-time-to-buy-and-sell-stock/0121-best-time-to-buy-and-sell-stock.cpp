class Solution {
public:

    // int solve(vector<int>& arr, int j,int Maxx,vector<int>&dp){
    //     if(j < 0) return 0;

    //     if(dp[j] != -1) return dp[j];

    //     int Profit = 0;
    //     if(arr[j] > Maxx) Maxx = arr[j];
    //     else{
    //         Profit = Maxx-arr[j];
    //     }

    //     int possProfit = solve(arr,j-1,Maxx,dp);

    //     return dp[j] = max(possProfit,Profit);

    // }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        // return solve(prices,n-1,INT_MIN,dp);
        int Minn = INT_MAX;
        for(int j = 1 ; j <= n ; j++){

            int Profit = 0;
           
            if(arr[j-1] < Minn) Minn = arr[j-1];
            else{
                Profit = arr[j-1] - Minn;
            }
            int possProfit = dp[j-1];

            dp[j] = max(Profit,possProfit);
        }

        return dp[n];    
    }
};