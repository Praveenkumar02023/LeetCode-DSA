class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sumArray;
       
        for(int i = 0 ; i < n; i++){
            int sum = 0;
            for(int j = i ; j < n ; j++){

                sum += nums[j];

                sumArray.push_back(sum);
            }
        }

        sort(sumArray.begin() , sumArray.end());
     int maxx = 1000000007;
        left = left-1 , right = right-1;
        int sum = 0;
        while(left <= right){
            sum += sumArray[left];
             sum = sum % maxx;

            left++;
        } 
       
        return sum;

    }
};