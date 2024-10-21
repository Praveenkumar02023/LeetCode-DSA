class Solution {
public:
    int f(int i , int sum , int target , int n , vector<int>& nums){

        if(i == n){
            if(sum == target) return 1;
            return 0;
        }

        
        int plus = f(i+1,sum + nums[i],target,n,nums);
        int minus = f(i+1,sum-nums[i],target,n,nums);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return f(0,0,target,n,nums);    
    }
};