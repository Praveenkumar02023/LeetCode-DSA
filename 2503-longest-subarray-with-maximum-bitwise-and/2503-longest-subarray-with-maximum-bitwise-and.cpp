class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int maxNum = 0;

        for(auto num : arr){
            maxNum = max(maxNum,num);
        }

        int len = 0;
        int maxlen = 0;

        for(int i = 0 ; i < n ; i++){

            if(arr[i] == maxNum){
                len += 1;
            }else{
                maxlen = max(maxlen,len);
                len = 0;
            }
        }
         maxlen = max(maxlen,len);

        
        return maxlen;
    }
};