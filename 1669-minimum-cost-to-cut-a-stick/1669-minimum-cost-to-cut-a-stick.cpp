class Solution {
public:
    // int solve(int i , int j , vector<int>& cuts,vector<vector<int>> & dp){
    //     if(i > j) return 0;

    //     if(dp[i][j] != - 1) return dp[i][j];


    //     int minn = 1e9;
    //     for(int k = i ; k <= j ; k++){
            
    //         int cut = (cuts[j+1] - cuts[i-1]) + solve(i,k-1,cuts,dp) + solve(k + 1 , j,cuts,dp);

    //         minn = min(minn , cut); 
    //     }

    //     return dp[i][j] = minn;
    // }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,0));
        // return solve(1, cuts.size() - 2, cuts,dp);

        for(int i = c-2 ; i > 0 ; i--){
            for(int j = i ; j <= c-2 ; j++){

                int minn = INT_MAX;
                for(int k = i ; k <= j ; k++){
            
                    int cut = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k + 1][j];

                    minn = min(minn , cut); 
                }

                dp[i][j] = minn;

            }
        }

    return dp[1][c-2];

    }
};