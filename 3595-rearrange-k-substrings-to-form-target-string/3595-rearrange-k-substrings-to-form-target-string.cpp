class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size() ;
        int m = t.size();
        if(n % k != 0 || m % k != 0) return false;

        unordered_map<string,int> map;
        int reqSize = n/k;
        string temp = "";
        for(auto & ch : s){
            temp += ch;
            if(temp.size() == reqSize){
                map[temp] += 1;
                temp = "";
            }
        }

        temp = "";
        for(auto &ch : t){
            temp += ch;
            if(temp.size() == reqSize){
                if(map.find(temp) == map.end()) return false;
                else {
             
                map[temp] -= 1;
                if(map[temp] == 0) map.erase(temp);
                   temp = "";
                }
            }
        }

        return true;
    }
};