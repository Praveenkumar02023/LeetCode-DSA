class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int MaxLen = 0;
        //Brute - force


        // for(int i = 0 ; i < n ; i++){
        //     int zeroes = 0;
        //     for(int j = i  ; j < n ; j++){
        //         if(nums[j] == 0) zeroes++;
        //         if(zeroes <= k){
        //             MaxLen = max(MaxLen , j-i+1);
        //         }else{
        //             break;
        //         }
        //     }
        // }


        // better

        // int Left = 0 , Right = 0;
        // int Zero = 0;

        // while(Right < n){
        //     if(nums[Right] == 0) Zero++;

        //     while(Zero > k){
        //         if(nums[Left] == 0) Zero--;
        //         Left++;
        //     } 

        //     if(Zero <= k){
        //         MaxLen = max(MaxLen, Right-Left+1);
        //     }
        //     Right++;
        // }


        // Best

        int i = 0 , j = 0, zeroes = 0;

        while(j < n){

            if(nums[j] == 0) zeroes++;

            if(zeroes > k){
                if(nums[i] == 0) zeroes--;
                i++;
            }

            if(zeroes <= k){
                MaxLen = max(MaxLen,j-i+1);
            }
            j++;
        }


        return MaxLen;
    }
};