class Solution {
public:
    int f(int i , int sum , vector<int>& nums, vector<vector<int>>& dp){

        if(i == 0){
            
            if(sum == 0 && nums[i] == 0) return 2;
            if(sum == 0) return 1;
            return nums[i] == sum;
        }

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 0;
        if(sum >= nums[i]) take = f(i-1,sum-nums[i],nums,dp);
        int notTake = f(i-1,sum,nums,dp);

        return dp[i][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int reqSum = (totalSum - target)/2;

        if((totalSum - target) < 0 || (totalSum - target) % 2 == 1) return 0;


        vector<vector<int>>dp(n+1 , vector<int>(reqSum + 1 , -1)); 
        return f(n-1,reqSum,nums,dp);
    }
};