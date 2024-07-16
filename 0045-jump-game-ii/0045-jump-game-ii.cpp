class Solution {
public:
    // int solve(int i , vector<int>& nums ,int n,vector<int>& dp){

    //     if(i >= n-1) return 0;
        
    //     if(dp[i] != -1) return dp[i];

    //     int step = nums[i];

    //     int jump = 1e9+7;

    //     for(int j = 1 ; j <= step ; j++){

    //         jump = min(jump,1 + solve(i+j,nums,n,dp));

    //     }

    //     return dp[i] = jump;

    // }

    int jump(vector<int>& nums) {
        int n = nums.size();

        // vector<int> dp(n , -1);
        // return solve(0,nums,n,dp);

        int jump = 0;
        int l = 0 , r = 0 ;
        while(r < n-1){
            int far = 0;

            for(int i = l ; i <= r ; i++){
                far = max(far,i+nums[i]);
            }
            l = r + 1;
            r = far;
            jump++;
        }

        return jump;
    }
};