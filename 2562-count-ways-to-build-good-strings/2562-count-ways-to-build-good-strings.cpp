class Solution {
public:
    int getNumOfStrings(int low,int high , int zero , int one , int stringSize,vector<int>&dp){

        if(stringSize > high) return 0;
        if(dp[stringSize] != -1) return dp[stringSize];
     
        int takeZero = getNumOfStrings(low,high,zero,one,stringSize + zero,dp);
        // cout<<"takeZero"<<takeZero<<endl;
        int takeOne = getNumOfStrings(low,high,zero,one,stringSize + one,dp);
        // cout<<"takeone"<<takeOne<<endl;

        if(stringSize >= low && stringSize <= high){
            return dp[stringSize] =  (1 + takeZero + takeOne)%1000000007;
        }
        
        return dp[stringSize] = (takeZero + takeOne)%1000000007;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high + 2 , -1);
        int stringSize = 0;
        return getNumOfStrings(low,high,zero,one,stringSize,dp);
    }
};