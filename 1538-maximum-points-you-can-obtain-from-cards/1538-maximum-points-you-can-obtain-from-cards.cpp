class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int LeftSum = 0 , RightSum = 0, MaxSum = 0;

        for(int i = k-1 ; i >= 0 ; i--) LeftSum += cardPoints[i];

        MaxSum = LeftSum;

        int Rind = cardPoints.size()-1;

        for(int i = k-1 ; i >= 0 ; i--){
            LeftSum -= cardPoints[i];
            RightSum += cardPoints[Rind];
            Rind--;

            MaxSum = max(MaxSum,LeftSum + RightSum);
        }

        return MaxSum;
    }
};