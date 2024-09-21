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

        vector<vector<int>> t(n+1,vector<int>(sum+1,-1));

        return f(n,sum/2,nums,t);

    }
};