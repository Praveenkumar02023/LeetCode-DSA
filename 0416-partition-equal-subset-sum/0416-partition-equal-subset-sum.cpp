class Solution {
public:
     bool f(int i , int n , vector<int>&arr , int sum, vector<vector<int>>&dp){
        
        if(i >= n ){
            if(sum == 0) return true;
            return false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool pick = false;
        if(sum >= arr[i]) pick = f(i+1,n,arr,sum-arr[i],dp);
        bool notPick = f(i+1,n,arr,sum,dp);
        return dp[i][sum] = pick || notPick;
        
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin() ,nums.end(),0);

        if(sum % 2 != 0) return false;

        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(0,n,nums,sum,dp);
    }
};