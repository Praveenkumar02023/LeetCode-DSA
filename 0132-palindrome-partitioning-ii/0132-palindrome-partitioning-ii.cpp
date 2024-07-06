class Solution {
public:
    bool isPalindrome(int i ,int j , string &s){
        
       
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i , string & s,vector<int> & dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int min_cut = 1e9;
        for(int j = i ; j < s.size() ; j++){

           
            if(isPalindrome(i,j,s)){
                min_cut = min(min_cut,1 + solve(j+1,s,dp));
            }

           
        }    

        return dp[i] = min_cut;

    }

    int minCut(string s) {
        if(isPalindrome(0,s.size() - 1 , s)) return 0;
        vector<int> dp(s.size() , -1);
        return solve(0,s,dp)-1;
    }
};