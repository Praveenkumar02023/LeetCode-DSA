class Solution {
public:
    

    bool canPartition(vector<int>& nums) {
       int n = nums.size();
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum % 2 != 0) return 0;

        vector<vector<int>> t(n+1,vector<int>((sum/2)+1,0));

        for(int i = 0 ; i < n+1 ; i++){

            t[i][0] = 1; 
        }

        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < (sum/2)+1 ; j++){
                int take = 0;
                if(j >= nums[i-1]) take = t[i-1][j-nums[i-1]];

                int notTake = t[i-1][j];

                t[i][j] = (take || notTake);
            }
        }
        return t[n][sum/2];
    }
};