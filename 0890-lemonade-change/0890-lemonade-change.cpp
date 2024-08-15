class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int fiveChange = 0 , tenChange = 0 ;

        for(auto x : bills){

            if( x == 5) fiveChange++;

            else if( x == 10){

                if(fiveChange < 1) return false;
                else{
                    fiveChange -= 1;
                    tenChange += 1;
                }
            }
            else{
                if( tenChange >= 1 && fiveChange >= 1){

                    tenChange -= 1;
                    fiveChange -= 1;
                }
                else if(fiveChange >= 3 ){
                    fiveChange -= 3;
                }
                else return false;
            }

        }

        return true;

    }
};