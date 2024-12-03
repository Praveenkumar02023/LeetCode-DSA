class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();

        string res = "";
        if(spaces.empty()) return s;
        
        int spaceIndex = spaces[0];
        res += s.substr(0,spaceIndex) + " ";
       

        for( int i = 1; i <= n ;i++ ){
            if(i == n){
                 res += s.substr(spaces[i-1] ,n - res[i-1]);
            }else{

            spaceIndex = spaces[i];
            res += s.substr(spaces[i-1] ,spaceIndex - spaces[i-1] ) + " ";
            }
        }
        
        if(res.back() == ' ') res.pop_back();
        return res;

    }
};