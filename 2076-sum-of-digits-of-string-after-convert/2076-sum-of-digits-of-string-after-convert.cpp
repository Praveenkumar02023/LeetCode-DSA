class Solution {
public:

    int sumOfDigits(string nums,int k){
       int num = 0;
       string temp = nums; 
       while(k--){
        num = 0;
        for(auto ch : temp){

            num += ch-'0';

        }

        temp = to_string(num);
       }

        return num;

    }
    int getLucky(string s, int k) {
       string nums = "";

       for(auto ch: s){
        nums += to_string(ch-'a'+1);
       }
       

       return sumOfDigits(nums,k); 
    }
};