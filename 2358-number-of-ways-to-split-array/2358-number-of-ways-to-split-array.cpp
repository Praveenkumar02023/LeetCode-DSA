class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<long long> preSum(n);

        preSum[0] = nums[0];

        for(long long i = 1 ; i < n ; i++){
            preSum[i] += preSum[i-1] + nums[i];
        }

        int validSplit = 0;

        for(int i = 0 ; i < n-1 ; i++){

            long long leftSum = preSum[i];
            long long rightSum  = preSum[n-1]-leftSum;

            if(leftSum >= rightSum){
                validSplit++;
            }

        }
        return validSplit;
    }
};