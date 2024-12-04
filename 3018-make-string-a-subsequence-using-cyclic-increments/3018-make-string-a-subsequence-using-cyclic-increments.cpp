class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n = str1.size();
        int m = str2.size();

        while(i < n && j < m){
            
            char prev = 'a';
            if(str2[j] == 'a'){
                prev = 'z';
            }else{
                prev = str2[j] - 1;
                cout<<prev<<" ";
            }

            if(str1[i] == str2[j] || prev == str1[i]){
                j++;
            }
            i++;
        }
        if(j >= m) return true;
        return false;
    }
};