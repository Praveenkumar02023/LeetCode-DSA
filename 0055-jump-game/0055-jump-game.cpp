class Solution {
public:
    // bool solve(int i , vector<int>& nums , int n,vector<int>& dp){
    //     if(i == n-1) return true;
    //     if(i >= n) return false;

    //     if(dp[i] != -1) return dp[i];

    //     int step = nums[i];

       

       
    //     for (int j = 1; j <= step; ++j) {
    //         if (solve(i + j, nums, n,dp)) {
    //             return dp[i] = true;
    //         }
    //     }

    //     return dp[i] = false;
    // }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // vector<int> dp(n,-1);

        // return solve(0,nums,n,dp);

        int MaxIdx = 0;

        for(int i = 0 ; i < n ; i++){
            if(i > MaxIdx) return false;
            MaxIdx = max(MaxIdx,i+nums[i]);
        }

        return true;
    }
};