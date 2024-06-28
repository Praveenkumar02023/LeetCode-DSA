class Solution {
public:
    int solve(int i , int j, vector<int>& nums,vector<vector<int>> & dp){
        if(j < 0) return 0;
        
    if(dp[i+1][j] != -1) return dp[i+1][j];

        int take = 0;
        if(i == -1 || nums[j] < nums[i]){
            take = 1 + solve(j,j-1,nums,dp);
        }

        int notTake = solve(i,j-1,nums,dp);

        return dp[i+1][j] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(-1,n-1,nums,dp);
    
    }
};