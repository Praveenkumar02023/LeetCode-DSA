class Solution {
public:
    int solve(int i,int sum ,vector<int>&nums,int target,vector<vector<int>>&mem,int totalSum){

        if(i == nums.size()){

            if(sum == target)return 1;
            else return 0;
        }
        
        if(mem[i][sum + totalSum] != -1) return mem[i][sum + totalSum];

        int plus = solve(i+1,sum + nums[i],nums, target,mem,totalSum);

        int minus = solve(i+1,sum - nums[i],nums,target,mem,totalSum);

        return mem[i][sum+totalSum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> mem(n+1,vector<int>(2*sum + 1 , -1));

        return solve(0,0,nums,target,mem,sum);
    }
};