class Solution {
public:
    bool isPossible(vector<int>&nums,int maxOp , int curMaxBalls){

        int curOp = 0;
        for(auto & num : nums){
            curOp += num/curMaxBalls;
            if(num % curMaxBalls == 0) curOp--;
            if(curOp > maxOp) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l = 1 , r = *max_element(begin(nums),end(nums));
        int maxNumBalls = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(nums,maxOperations,mid)){
                maxNumBalls = mid;
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }

        return maxNumBalls;
    }
};