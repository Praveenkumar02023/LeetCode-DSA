class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1) , hash(n);

        int maxLen = 1;
        int lastInd = 0;

        for(int i = 0; i < n ; i++ ){
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[i] % nums[prev] == 0 && (1 + dp[prev] > dp[i])){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if(maxLen < dp[i]){
                maxLen = dp[i];
                lastInd = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastInd]);

        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }

        reverse(temp.begin() , temp.end());

        return temp;
    }
};