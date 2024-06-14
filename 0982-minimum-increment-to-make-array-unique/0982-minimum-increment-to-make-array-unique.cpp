class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>num(begin(nums),end(nums));
        sort(num.begin(),num.end());
        int Cnt = 0;
        for(int i = 1 ; i < num.size() ; i++){
            if(num[i] <= num[i-1]){
                int temp = num[i];
                num[i] += (num[i-1]-num[i])+1;
                Cnt += num[i]-temp;
            }
        }

        return Cnt;
    }
};