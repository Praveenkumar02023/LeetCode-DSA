class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int xorRes = start ^ goal;
        long long res = 0;
        while(xorRes > 0){

            if(xorRes % 2 == 1) res += 1;
            xorRes = xorRes / 2;
        }


        return res;

    }
};