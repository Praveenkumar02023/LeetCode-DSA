class Solution {
public:
    int countPalindromicSubsequence(string s) {
     
        int n = s.size();

        vector<int> fOccu(26,-1);
        vector<int> lOccu(26,-1);
        
        for(int i = 0 ; i < n; i++){
            int ch = s[i]-'a';
            if(fOccu[ch] == -1){
                fOccu[ch] = i;
            }
            lOccu[ch] = i;
        }

        int totalSubSeq = 0;

        for(int i = 0 ; i < 26 ; i++){

            
            int leftIndex = fOccu[i];
            int RightIndex = lOccu[i];

            if(leftIndex == -1)continue;

            unordered_set<char>st;
            for(int k = leftIndex + 1 ; k < RightIndex ; k++){

                char ch = s[k];
                st.insert(ch);

            }

            totalSubSeq += st.size();

        }

        return totalSubSeq;      
    }
};