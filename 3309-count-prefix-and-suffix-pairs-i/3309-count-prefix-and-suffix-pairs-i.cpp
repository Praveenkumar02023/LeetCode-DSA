class Solution {
public:
    bool isSuffixAndPrefix(string s1 , string s2){

        int n = s1.size();
        int m = s2.size();

        if(m < n) return false;

        for(int i = 0 ; i < n ; i++){

            if(s1[i] != s2[i] || s1[i] != s2[m-n + i]) return false;  

        }

        return true;

    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n = words.size();

        int cnt = 0;

        for(int i = 0 ; i < n  ; i++){

            for(int j = i + 1 ; j < n ; j++){

                if(isSuffixAndPrefix(words[i],words[j])){

                    cnt += 1;

                }

            }
        }

        return cnt ;
    }
};