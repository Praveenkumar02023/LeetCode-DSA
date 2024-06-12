class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int MaxLen = 0;
        vector<int> arr(26,0);       
       int i = 0 , j = 0 , maxf= 0;

       while(j < n){

        arr[s[j] - 'A']++;

        maxf = max(maxf,arr[s[j]-'A']);

        while((j-i+1) - maxf > k){
            arr[s[i]-'A']--;
            i++;
            for(int k = 0 ; k < 26 ; k++){
                maxf = max(maxf,arr[k]);
            }
        }

        if((j-i+1) - maxf <= k){
            MaxLen = max(MaxLen,j-i+1);
        
        }
        j++;
       }
        
        return MaxLen;
    }
};