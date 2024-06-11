class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int MaxLen = 0;
        int i  = 0 , j = 0;
        unordered_map<int,int> mp;

        while(j < n){

            mp[fruits[j]]++;

            if(mp.size() > 2){
                mp[fruits[i]]--;
                if( mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            if(mp.size() <= 2){
                MaxLen = max(MaxLen,j-i+1);
            }
            j++;
        }
        return MaxLen;
    }
};