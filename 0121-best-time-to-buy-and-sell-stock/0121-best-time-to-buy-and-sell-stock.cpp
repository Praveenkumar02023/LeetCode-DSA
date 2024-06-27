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
       int MaxProfit = 0; 
        // return solve(prices,n-1,INT_MIN,dp);
        int Minn = INT_MAX;
        for(int j = 0 ; j < n ; j++){

            int Profit = 0;
           
            if(arr[j] < Minn) Minn = arr[j];
            else{
                Profit = arr[j] - Minn;
            }
            MaxProfit = max(Profit,MaxProfit);
        }

        return MaxProfit;    
    }
};