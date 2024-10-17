class Solution {
public:
    int f(vector<int>&nums){
         int n = nums.size();
        vector<int> dp(n+1,0);
            if(n == 1) return nums[0];

            dp[0] = nums[0];
            dp[1] = max(nums[0] , nums[1]);
       

        for(int i = 2 ; i < n ; i++){
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n==0) return 0;
         vector<int> arr1;
         vector<int> arr2;

    

         for(int i = 0 ; i < n ; i++){
            if(i != 0 ) arr1.push_back(nums[i]);
            if(i != n-1 ) arr2.push_back(nums[i]);
         }
         int ans = max(f(arr1),f(arr2));

         return ans;
    }
};