class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if((nums[i] + flip%2) != 1){
                cnt++;
                flip++;
            }
        }

        return cnt;
    }
};