class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        int maxx = 1;
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev_ind = 0 ; prev_ind < ind ; prev_ind++){
                if(nums[ind] > nums[prev_ind]){
                    dp[ind] = max(dp[ind] , 1 + dp[prev_ind]);
                }
            }

            maxx = max(maxx , dp[ind]);

        }

        return maxx;
    }
};