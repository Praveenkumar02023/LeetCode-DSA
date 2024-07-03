class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<int> dp(n,1) , cnt(n,1);



        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev++){

                if(nums[i] > nums[prev] && ( 1 + dp[prev] > dp[i])){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }else if(nums[i] > nums[prev] && (1 + dp[prev] == dp[i])){
                    cnt[i] += cnt[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int no = 0;
        for(int i = 0 ; i < n ; i++){
            cout<<cnt[i];
            if(dp[i] == maxi) no += cnt[i];
        }
        return no;

    }
};