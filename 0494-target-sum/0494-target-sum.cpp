class Solution {
public:
    int solve(int i,int sum ,vector<int>&nums,int target,unordered_map<string,int>& mem){

        if(i == nums.size()){

            if(sum == target)return 1;
            else return 0;
        }
        string curr = to_string(i) + "_" + to_string(sum);

        if(mem.count(curr)) return mem[curr];

        int plus = solve(i+1,sum + nums[i],nums, target,mem);

        int minus = solve(i+1,sum - nums[i],nums,target,mem);

        return mem[curr] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string,int> mem;
        return solve(0,0,nums,target,mem);
    }
};