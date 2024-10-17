class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
            if(n == 1) return nums[0];

            dp[0] = nums[0];
            dp[1] = nums[1];
       

        for(int i = 0 ; i < n ; i++){
            
            for(int j = i + 2 ; j < n ; j++){
                
                dp[j] = max(dp[j] , nums[j] + dp[i]);

            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};