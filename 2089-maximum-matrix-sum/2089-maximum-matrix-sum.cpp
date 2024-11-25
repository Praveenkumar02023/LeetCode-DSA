class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCnt = 0;
        long long sum = 0;
        int minEle = 1e9+7;
        for(auto row : matrix){
            for(auto x : row){
                if(x < 0) negCnt += 1;
                sum += abs(x);
                minEle = min(minEle,abs(x));
            }
        }

        if(negCnt % 2 == 0) return sum;
        else return sum - 2 * minEle;
        
    }
};