class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long,long long> freq;
        int n = hours.size();

        long long res = 0;

        for(int i = 0 ; i < n ; i++){

            int rem = hours[i]%24;

            if(rem == 0){
                res += freq[0];
            }else{
                res += freq[24-rem];
            }

            freq[rem]++;
        }

        return res;
    }
};