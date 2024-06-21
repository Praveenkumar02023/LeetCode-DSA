class Solution {
public:
    int solve(int i , int sum , vector<int>& nums,vector<vector<int>> & dp){
        if(i == 0 ){
            if(nums[0] == 0 && sum == 0) return 2;
            if(nums[0] == sum || sum == 0) return 1;

            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        int notPick = solve(i-1,sum,nums,dp);
        int Pick = 0;
        if(nums[i] <= sum) Pick = solve(i-1,sum-nums[i] , nums,dp);

        return dp[i][sum] = (notPick + Pick);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto num : nums) totalSum += num;

        int sum = (totalSum-target)/2;
        if(((totalSum-target) < 0 ) || (totalSum-target)%2 != 0 ) return 0;

        vector<vector<int>> dp(nums.size(),vector<int>(sum + 1 , -1));

        return solve(nums.size()-1,sum,nums,dp);
    }
};