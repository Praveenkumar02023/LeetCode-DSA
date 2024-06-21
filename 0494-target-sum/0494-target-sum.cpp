class Solution {
public:
    int solve(int i , int sum , vector<int>& nums){
        if(i == 0 ){
            if(nums[0] == 0 && sum == 0) return 2;
            if(nums[0] == sum || sum == 0) return 1;

            return 0;
        }

        int notPick = solve(i-1,sum,nums);
        int Pick = 0;
        if(nums[i] <= sum) Pick = solve(i-1,sum-nums[i] , nums);

        return notPick + Pick;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for(auto num : nums) totalSum += num;

        if(((totalSum-target) < 0 ) || (totalSum-target)%2 == 1) return 0;

        int sum = (totalSum-target)/2;

        return solve(nums.size()-1,sum,nums);
    }
};