class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int arraySum = 0;
        unordered_map<int, int> mp;
        int outlier = INT_MIN;

        for (int num : nums) {
            arraySum += num;
            mp[2 * num] += 1;
        }

        for(int num : nums){

            int curSum = arraySum - num;

            if(mp[curSum] > 1 || (mp[curSum] == 1 ) && (curSum != num*2) ){
                outlier = max(outlier,num);
            } 

            
        }
        return outlier;
    }
};