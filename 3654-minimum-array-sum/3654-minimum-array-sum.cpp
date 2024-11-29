class Solution {
public:
    int helper(int i, int op1, int op2, int n, vector<int>& nums, int k, vector<vector<vector<int>>>& dp) {

        if (i == n)
            return 0;

        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];

        int sum = INT_MAX;
        
        //op1 -> op2
        //op2 -> op1

        if (op1 > 0 && op2 > 0) {
          int newVal = (nums[i] + 1) /2;

          if(newVal >= k){
            newVal -= k;
            int applyOp1Op2 = newVal + helper(i+1,op1-1,op2-1,n,nums,k,dp);
            sum = min(sum,applyOp1Op2);
          }

          if(nums[i] >= k){
            
          newVal = nums[i] - k;

          newVal = (newVal + 1) / 2;
          int applyOp2Op1 = newVal + helper(i+1,op1-1,op2-1,n,nums,k,dp);
          sum = min(sum,applyOp2Op1); 

          }  
        }

        //op1
        if (op1 > 0) {
          int newVal = (nums[i] + 1)/2;
          sum = min(sum , newVal + helper(i+1,op1-1,op2,n,nums,k,dp));
        }

        //op2
        if (op2 > 0 && nums[i] >= k) {
          int newVal = nums[i] - k;
          sum = min(sum , newVal + helper(i+1,op1,op2-1,n,nums,k,dp));
        }
        //no op
        sum = min(sum, nums[i] + helper(i + 1, op1, op2, n, nums, k,dp));
        return dp[i][op1][op2] = sum;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return helper(0, op1, op2, n, nums, k,dp);
    }
};