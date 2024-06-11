class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        // for(int i = 0 ; i < n ; i++){
        //     unordered_map<char,int> mp;

        //     for(int j = i ; j < n ; j++){

        //         mp[s[j]]++;

        //         if(mp.size() == 3){
        //             cnt++;
        //         }
        //     }

        // }
        vector<int> LastSeen(3,-1);
        for(int i = 0 ; i < n ; i++){
            LastSeen[s[i]-'a'] = i;

            if(LastSeen[0] != -1 && LastSeen[1] != -1 && LastSeen[2] != -1){
                cnt += min({LastSeen[0],LastSeen[1],LastSeen[2]}) + 1;
            }
        }
        return cnt;
    }
};