class Solution {
public:
    // int solve(int i , vector<int> & arr , int transaction,int buy,vector<vector<vector<int>>>& dp){
    //     if(transaction == 0) return 0;
    //     if(i == arr.size()) return 0;

    //     if(dp[i][transaction][buy] != -1) return dp[i][transaction][buy];

    //     int take = 0;
    //     if(buy){
    //         take = max((arr[i] + solve(i+1,arr,transaction-1,false,dp)),(solve(i+1,arr,transaction,true,dp)));
    //     }else{
    //         take = max((-arr[i] + solve(i+1,arr,transaction,true,dp)),(solve(i+1,arr,transaction,false,dp)));
    //     }

    //     return dp[i][transaction][buy] = take;

    // }

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        // return solve(0,prices,2,false,dp);

        for(int i = n-1 ; i >=0  ; i--){
            for(int transaction = 2 ; transaction > 0 ; transaction--){
                for(int k = 0 ; k <= 1 ; k++){
                        int take = 0;
                        if(k == 1){
                                take = max((arr[i] + dp[i+1][transaction-1][false]),(dp[i+1][transaction][true]));
                        }else{
                            take = max((-arr[i] +  dp[i+1][transaction][true]),( dp[i+1][transaction][false]));
                        }
                        dp[i][transaction][k] = take;
                }
            }
        }

        return dp[0][2][0];
    }
};


