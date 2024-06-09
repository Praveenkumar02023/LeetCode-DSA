class Solution {
public:
//using memoisation
    int t[301];
    bool solve(int i , string &s,unordered_set<string>& st){
        if(i >= s.size()){
            return true;
        }
        if(t[i] != -1) return t[i];
        if(st.find(s) != st.end()) return true;

        for(int l = 1; l <= s.size() ; l++){
            string temp = s.substr(i,l);
            if(st.find(temp) != st.end() && solve(i+l,s,st)) return t[i] = true;
        }

        return t[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin() , wordDict.end());

        memset(t,-1,sizeof(t));
        return solve(0,s,st);

    }
};