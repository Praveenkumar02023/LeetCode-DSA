class Solution {
public:

    int solve(vector<int>& arr, int j,int Maxx){
        if(j < 0) return 0;

        int Profit = 0;
        if(arr[j] > Maxx) Maxx = arr[j];
        else{
            Profit = Maxx-arr[j];
        }

        int possProfit = solve(arr,j-1,Maxx);

        return max(possProfit,Profit);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(prices,n-1,INT_MIN);
    }
};