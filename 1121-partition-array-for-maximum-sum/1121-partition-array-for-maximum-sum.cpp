class Solution {
public:

    int solve(int i , int n , vector<int>& arr , int k,vector<int>& dp ){
        if(i == n ) return 0;
        if(dp[i] != -1) return dp[i];

        int max_ele = INT_MIN;
        int cost = 0;
        for(int j = i ; j <  min(i+k,n) ; j++){
            max_ele = max(max_ele,arr[j]);

            int max_cost = (max_ele * (j - i + 1)) + solve(j+1,n,arr,k,dp);
            cost = max(cost,max_cost);

        }

        return  dp[i] = cost;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,n,arr,k,dp);
    }
};