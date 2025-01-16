class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<long long,long long> freq;

        for(auto num : nums1){

            freq[num] += m;

        }
         for(auto num : nums2){

            freq[num] += n;

        }

        long long ans = 0;

        for(auto it : freq){

            if(it.second & 1){
                ans ^= it.first;
            }

        }


        return ans;
    }
};