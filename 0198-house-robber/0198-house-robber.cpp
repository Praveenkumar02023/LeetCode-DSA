class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);

        dp[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int take = nums[i];
              if(i-2 >= 0)
              take += dp[i-2];

            int non_take = 0 + dp[i-1];

            dp[i] = max(take,non_take);
        }

        return dp[nums.size()-1];
    }
};