class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int xorSum = 0;

        for(auto num : derived){
            xorSum ^= num;
        }  

        if(xorSum == 0) return true;
        return false;

    }
};