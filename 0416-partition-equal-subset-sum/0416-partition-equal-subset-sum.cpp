class Solution {
public:
    bool canPartition(vector<int>& arr) {

        int sum = 0;
        for(auto & num : arr) sum += num;
        if(sum % 2) return false;

        sum = sum / 2;
         vector<int> dp(sum+1,0);
        // return solve(arr.size()-1,sum,arr,dp);
        
        
        dp[0] = 1;
        
        
        if(arr[0] <= sum)
            dp[arr[0]] = 1;
        
        for(int i = 1 ; i < arr.size() ; i++){
            vector<int>curr(sum+1,0);
            
            curr[0] = 1;
            for(int target = 1 ; target <= sum ; target++){
                int NotPick = dp[target];
                int pick = 0;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                
                curr[target] = (pick || NotPick);
            }
            dp = curr;
        }
        
        return dp[sum];
    }
};