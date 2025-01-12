class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        stack<int> open;
        stack<int> unlock;

        for(int i = 0 ; i < n ;i++){

            if(locked[i] == '0'){
                unlock.push(i);
            }
            else{

                if(s[i] == '('){
                    open.push(i);
                }else{

                    if(!open.empty()){
                        open.pop();
                    }else if(!unlock.empty()){
                        unlock.pop();
                    }else return false;
                }
            }
        }

        while(!open.empty() && !unlock.empty()){

            int openIdx = open.top();
            open.pop();

            int unlockIdx = unlock.top();
            unlock.pop();

            if(unlockIdx < openIdx) return false;
        }

        if(open.size() > 0 || unlock.size() % 2 != 0) return false;

        return true;
    }
};