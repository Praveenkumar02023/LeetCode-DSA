class Solution {
public:
    int Cnt(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, cnt = 0;

        unordered_map<int, int> mp;

        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            if (mp.size() <= k) {
                cnt += (j - i + 1);
            }

            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // for(int i = 0 ; i < n ; i++){
        //     unordered_set<int> st;

        //     for(int j = i ; j < n ; j++){
        //         st.insert(nums[j]);
        //         if(st.size() == k) cnt++;
        //     }

        // }

        return Cnt(nums, k) - Cnt(nums, k - 1);
    }
};