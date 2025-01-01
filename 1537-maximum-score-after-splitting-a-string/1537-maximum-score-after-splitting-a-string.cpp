class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        
        int zeroCnt = 0;
        int maxRes = 0;
        for(int i = 0 ; i < n-1 ; i++){
            int oneCnt = 0;
            if(s[i] == '0') zeroCnt++;
            for(int j = i+1 ; j < n ; j++){

                if(s[j] == '1')oneCnt++;

            }
            maxRes = max(maxRes,oneCnt + zeroCnt);
        }

        return maxRes;
    }
};