class Solution {
public:
    // int solve(int i , vector<int>& arr , bool buy,vector<vector<int>> & dp){
    //     if(i == arr.size() ) return 0;
    //     if(dp[i][buy] != -1) return dp[i][buy];
    //     int take = 0;
    //     if(buy){
    //         take  = max((arr[i] + solve(i+1,arr,false,dp)) ,  0 + solve(i+1,arr,true,dp));
    //     }else{
    //         take =  dp[i][buy] = max((-arr[i] + solve(i+1,arr,true,dp)) ,0 + solve(i+1,arr,false,dp));
    //     }

    //     return  dp[i][buy] = take;
    // }
       

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
       vector<int> cur(2,0);

        // return solve(0,prices,false,dp);
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= 1 ; j++){
                int take = 0;
                if(j){
                    take  = max((arr[i] + cur[false]) ,  0 + cur[true]);
                   
                }else{
                    take = max((-arr[i] + cur[true]) , cur[false]);
                }

                  cur[j] = take;
            }

           
        }
        return cur[0];

    }
};