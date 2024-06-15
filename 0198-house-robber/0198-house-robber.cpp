class Solution {
public:
    int solve(vector<int>& dp,vector<int>& nums,int i){
       
        if(i == 0) return nums[i];
        
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(dp,nums,i-2);

        int non_take = 0 + solve(dp,nums,i-1);

        return dp[i] = max(take,non_take);

    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);

        return solve(dp,nums,nums.size()-1);
    }
};