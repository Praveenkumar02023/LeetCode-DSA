class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size();

        vector<int>freq(26,0);

        for(int i = 0; i < n ; i++){

            char ch = s[i];

            freq[ch-'a']++;
        }

        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){

           if(freq[i] > 2){

            if(freq[i] % 2 == 0) cnt += freq[i]-2;
            else cnt += freq[i] - 1;

           } 

        }

        return n-cnt;

    }
};