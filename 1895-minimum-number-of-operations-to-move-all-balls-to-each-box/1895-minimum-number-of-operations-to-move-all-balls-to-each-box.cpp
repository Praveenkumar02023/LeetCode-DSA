class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;

        int n = boxes.size();

        for(int i = 0 ; i < n ; i++){
            int cost = 0;

            for(int j = 0 ; j < n ;j++){

                if(boxes[j] == '1'){
                    cost += abs(i-j);
                }

            }
            res.push_back(cost);
        }

        return res;
    }
};