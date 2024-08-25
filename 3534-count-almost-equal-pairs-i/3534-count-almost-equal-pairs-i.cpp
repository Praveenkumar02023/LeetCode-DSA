class Solution {
public:
    int checkGood(int first , int second){

        string fir = to_string(first);
        string sec = to_string(second);
      
        while(fir.size() < sec.size()) fir = '0' + fir;
        while(sec.size() < fir.size()) sec = '0' + sec;

        int a = -1 , b = -1;
        int diff = 0;

        for(int i = 0 ; i < fir.size() ; i++){

            if(fir[i] != sec[i]){

                diff += 1;

                if(diff == 1) a = i;
                else if(diff == 2) b = i;
                else return 0;
            }

        }
            if(diff == 2)
                swap(sec[a] , sec[b]);

            if(sec == fir) return 1;
             return 0;


    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();

        int res = 0;

        for(int i = 0 ; i < n-1 ; i++){

            for(int j = i + 1 ; j < n ; j++){

                int goodPair = checkGood(nums[i] , nums[j]);
                res += goodPair;

            }

        }

        return res;
    }
};