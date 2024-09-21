class Solution {
public:

    bool f(int n , int sum , vector<int>& nums,vector<vector<int>>& t){

        if(n == 0){
            if(sum == 0) return 1;
            return 0;
        }  

        if(t[n][sum] != -1) return t[n][sum];

        int take = 0;
        if(sum >= nums[n-1]){
            take = f(n-1,sum-nums[n-1],nums,t);
        }
        int notTake = f(n-1,sum,nums,t);
        return t[n][sum] = (take || notTake);
    }    

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