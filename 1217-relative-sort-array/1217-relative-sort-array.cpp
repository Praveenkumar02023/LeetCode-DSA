class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans ;

        map<int,int> mp;

        for(auto & num : arr1) mp[num]++;

        for(auto & num : arr2){
            while(mp[num]){
                ans.push_back(num);
                mp[num]--;
            }
        }

        for(auto & it : mp){
            while(it.second){
                ans.push_back(it.first);
                it.second--;
            }
        }

        return ans;
    }
};