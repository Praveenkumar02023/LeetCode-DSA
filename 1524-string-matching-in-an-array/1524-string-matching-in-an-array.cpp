class Solution {
public:
    bool checkSubString(string a , string b){
        
        int n = a.length();
        int m = b.length();

        if(m < n) return false;

        if(m == n){
            if(a == b) return true;
            else return false;
        }

        for(int i = 0 ; i < m ; i++){
            string sub = b.substr(i,n);
            if(sub == a) return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;

        int n = words.size();

        for(int i = 0 ; i < n ; i++){

            for(int j = 0; j < n ; j++){

                if(i == j)continue;

                bool isSubString = checkSubString(words[i],words[j]);
                
                if(isSubString){
                    res.push_back(words[i]);
                    break;
                }
            }

        }

        return res;
    }
};