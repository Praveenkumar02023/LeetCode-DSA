class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

       for(auto& c : num){

        while(ans.size() > 0 && ans.back() > c && k > 0){

            ans.pop_back();
            k--;
        }

        if(ans.size() > 0 || c != '0'){
            ans.push_back(c);
        }

       }

       while(ans.size() > 0 && k > 0){
        ans.pop_back();
        k--;
       }

       if(ans.size() == 0) return "0";
       else{
        return ans;
       }
    }
};