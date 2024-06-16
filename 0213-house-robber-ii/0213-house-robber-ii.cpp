class Solution {
public:

    int solve(vector<int>& nums) {
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
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1 , temp2;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
       
        return max(solve(temp1),solve(temp2));
    }
};