class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n % 2 != 0) return false;

       int open = 0;
       int close = 0;

        for(int i = 0 ; i < n ;i++){

            if(open < 0) return false;

            if(s[i] == '(' || locked[i] == '0') open++;
            else if(s[i] == ')') open--;
        }

        for(int i = n-1 ; i >= 0 ;i--){

            if(close < 0) return false;

            if(s[i] == ')' || locked[i] == '0') close++;
            else if(s[i] == '(') close--;
        }

        return true;
    }
};