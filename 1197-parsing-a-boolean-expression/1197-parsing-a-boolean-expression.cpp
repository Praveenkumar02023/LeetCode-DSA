class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>s;

        for(auto & ch : expression){

            if(ch == ')'){
                bool hasT = false, hasF = false;

                while(s.top() == 't' || s.top() == 'f'){
                    if(hasT == false && s.top() == 't') hasT = true;
                    if(hasF == false && s.top() == 'f') hasF = true;

                    s.pop();
                }

                char op = s.top();
                s.pop();

                if(op == '&'){
                    if(hasF){
                        s.push('f');
                    }else{
                        s.push('t');
                    }
                }

                else if(op == '|'){
                    if(hasT){
                        s.push('t');   
                    }else s.push('f');
                }

                else{
                    if(hasT) s.push('f');
                    else s.push('t');
                }
            }else{
                if(ch != ',' && ch != '(') s.push(ch);
            }


        }

        return s.top() == 't';
    }
};