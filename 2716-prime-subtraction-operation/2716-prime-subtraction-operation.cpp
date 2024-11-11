class Solution {
public:
   

    vector<int> getPrime(int n){
        vector<int> PrimeOrNot(n+1,1);
        vector<int> Prime;
        
        for(int i = 2 ; i <= 1000 ; i++){
            if(PrimeOrNot[i] == 0) continue;

            for(int j = i * i ; j <= 1000 ; j += i){

                PrimeOrNot[j] = 0;

            }
        }

        for(int i = 2 ; i <= 1000 ; i++){
            if(PrimeOrNot[i]) Prime.push_back(i);
        }

        return Prime;
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        prime = getPrime(1000);

        int next = nums[nums.size()-1];
        int flag = true;      
       for(int i = nums.size()-2 ; i >= 0 ;i--){
           
           if(nums[i] < next){
            next = nums[i];
             continue;
            }
           flag = false;

           for(int p = 0 ; p < prime.size() && prime[p] < nums[i] ; p++){

                if(nums[i] - prime[p] < next){
                    flag = true;
                     next = nums[i] - prime[p];
                    break;
                }
           } 
           if(!flag)return flag;
       }

        return flag;
    }
};