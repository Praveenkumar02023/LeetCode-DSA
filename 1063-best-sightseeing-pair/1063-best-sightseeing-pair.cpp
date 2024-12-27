class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int n = values.size();

        int maxLeftScore = values[0];
        for(int i = 1 ; i < n ; i++){

            int curRightScore = values[i] - i;
            
            maxScore = max(maxScore,curRightScore + maxLeftScore);
            maxLeftScore = max(maxLeftScore,values[i] + i);
        }

        return maxScore;

    }
};