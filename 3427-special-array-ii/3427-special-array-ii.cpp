class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector<int> violatingNum(n);
        vector<bool> res;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] % 2 == 0 && nums[i-1]%2 == 0 || nums[i]%2 == 1 && nums[i-1]%2 == 1){
                violatingNum[i] = violatingNum[i-1] + 1;
            }else{
                violatingNum[i] = violatingNum[i-1];
            }
        }

        for(auto query : queries){

            int from = query[0];
            int to = query[1];

            if(violatingNum[to] - violatingNum[from] == 0){
                res.push_back(true);
            }else{
                res.push_back(false);
            }

        }

        return res;
    }
};