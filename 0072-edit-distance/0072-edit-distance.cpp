class Solution {
public:
    int helper(int i , int j , string& s , string& t,vector<vector<int>> &m){

        if(j == t.size()){
            if(i >= s.size()) return 0;
            else return s.size() - i ;
        }
        if(i >= s.size()) return 1e9+7;
        if(m[i][j] != -1) return m[i][j];

        if(s[i] == t[j]) return helper(i+1,j+1,s,t,m);

        //replace
        int replace = 1 + helper(i+1,j+1,s,t,m);
        //
        int del = 1 + helper(i+1,j,s,t,m);
        int ins = 1 + helper(i,j+1,s,t,m);

        return m[i][j] = min({replace , del , ins});
    }
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();
        vector<vector<int>> t(word1.size() + 1 ,vector<int>(word2.size() + 1,-1));
        return helper(0,0,word1,word2,t);
    }
};