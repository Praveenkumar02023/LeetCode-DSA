class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        vector<int> arr(256,-1);

        int left = 0, right = 0 , MaxLen = 0;

        while(right < s.size()){
            int ReIdx = arr[s[right]];
            if(ReIdx != -1){

                if(ReIdx >= left){
                    left = ReIdx + 1;
                }

            }

            int len = right - left + 1;

            MaxLen = max(MaxLen , len);

            arr[s[right]] = right;
            right++;
        }

        return MaxLen;

    }
};