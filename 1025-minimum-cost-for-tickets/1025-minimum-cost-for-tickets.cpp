class Solution {
public:
    int upperBound(vector<int>& days,int num){
        return upper_bound(days.begin(),days.end(),num)-days.begin();
    }

    int solve(int i , vector<int>&days,vector<int>&costs,int n,vector<int>&dp ){

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int takeOneDay = costs[0] + solve(i+1,days,costs,n,dp);

        int takeSevenDay = costs[1] + solve(upperBound(days,days[i]-1 + 7) , days,costs,n,dp);

        int takeThirtyDay = costs[2] + solve(upperBound(days,days[i]-1 + 30),days,costs,n,dp);


        return dp[i] = min({takeOneDay,takeSevenDay,takeThirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        int i = 0;
        vector<int> dp(n+1,-1);
        return solve(i,days,costs,n,dp);
    }
};