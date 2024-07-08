class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> Minh;

        for(int i = 0 ; i < nums.size() ; i++){
            Minh.push(nums[i]);

            if(Minh.size() > k) Minh.pop();
        }

        return Minh.top();
    }
};