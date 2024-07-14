class Solution {
public:
    // bool solve(int i , string & s , int cnt){

    //     if(cnt < 0) return false;

    //     if(i == s.size()){
    //         return (cnt == 0);
    //     }

    //     if(s[i] == '(') return solve(i+1,s,cnt+1);

    //     else if(s[i] == ')') return solve(i+1,s,cnt-1);

    //     else return (solve(i+1,s,cnt) || solve(i+1,s,cnt+1) || solve(i+1,s,cnt-1));

    // }

    bool solve(string s , int n){
        int minn = 0 , maxx = 0;

        for(int i = 0 ; i < n ; i++){

            if(s[i] == '('){
                minn += 1;
                maxx += 1;
            }
            else if(s[i] == ')'){
                minn -= 1;
                maxx -= 1;
            }
            else{
                minn -= 1;
                maxx += 1;

            }

            if(minn < 0) minn = 0;
            if(maxx < 0) return false;

        }

        return (minn == 0);
    }
    bool checkValidString(string s) {

        
        return solve(s,s.size());

    }
};