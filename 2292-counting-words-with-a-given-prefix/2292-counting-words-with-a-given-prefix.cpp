class Solution {
public:
    bool isPrefix(string str,string pref){


        int n = str.length();
        int m = pref.length();

        for(int i = 0 ; i < m  ; i++){


            if(str[i] != pref[i]) return false;


        }

        return true;

    }

    int prefixCount(vector<string>& words, string pref) {
        
        int cnt = 0 ;

        int n = words.size();
        int m = pref.size();

        for(int i = 0; i < n ;i++){

            if(words[i].size() < m) continue;

            if(isPrefix(words[i],pref)) cnt++;

        }

        return cnt;

    }
};