class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();

        unordered_map<int,int> mp;

        int indSearch = 0;
        int i = 0;
        int maxPartitions = 0;

        for(; i < n ;i++){

            if(arr[i] == indSearch){
                mp[arr[i]] += 1;
                maxPartitions += 1;
                while(indSearch <= i){
                    if(mp[indSearch] == 1) indSearch += 1;
                    else{
                        maxPartitions -= 1;
                        break;
                    }
                }
            }
            else{
                mp[arr[i]] += 1;
            }
        }

        return maxPartitions;
    }
};