class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums) total += x;

        for(int i = 0 ; i < n ; i++){
            nums.push_back(nums[i]);
        }

        int i = 0 , j = 0;
        int res = 1e9+7 , zeroCnt = 0;

        while(j < 2*n){

            if(nums[j] == 0)zeroCnt++;

            if(j-i+1 > total){

                if(nums[i] == 0){
                    zeroCnt--;
                    res = min(res,zeroCnt);
                }
                i++;
            }

           

            j++;

        } 

        return res == 1e9+7 ? 0 : res;

    }
};