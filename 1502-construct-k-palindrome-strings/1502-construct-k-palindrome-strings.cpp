class Solution {
public:
    bool canConstruct(string s, int k) {
       int n = s.length();
       if(n == k) return true;
       if(n < k) return false; 
       unordered_map<char,int>mp;

       for(auto ch: s){
            mp[ch]++;
       }

       if(mp.size() == k) return true;

       int oddCnt = 0;

       for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second % 2 != 0)oddCnt++;
       }

       if(oddCnt > k) return false;



       return true;

    }
};