class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0 , mid = 0; 
        int j = nums.size()-1;
        while(mid <= j){
            if(nums[mid] == 0){
                swap(nums[mid++],nums[i++]);
            }else if(nums[mid] == 2){
                swap(nums[mid],nums[j--]);
            }else{
                mid++;
            }
        }
        
    }
};