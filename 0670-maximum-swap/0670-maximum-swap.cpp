class Solution {
public:
    int maximumSwap(int num) {
       
        string s = to_string(num);
        
        int i = 0 ; 
        int j = s.size()-1 ;
        char maxChr = 'a';
        int ind = -1;
        while(i <= j){
            if(i == j && maxChr == 'a'){
                i++;
                j = s.size()-1;
            }else if(i == j){
                break;
            }
            if(s[i] < s[j]){
                if(maxChr == 'a'){
                maxChr = s[j];
                ind = j;
                } 
                else if(maxChr < s[j]){
                ind = j;
                maxChr = s[j];
                } 
                
            }
            j--;
        }

        if(i <= j && maxChr != 'a'){
            swap(s[i],s[ind]);
        }

        return stoi(s);

       
    }
};