class Solution {
public:
    int countSeniors(vector<string>& det) {
        int cnt = 0;

        for(auto &x : det){
           
          char a = x[11];
          char b = x[12];

          int senior = (a-'0')*10 + (b)-'0';
          if(senior > 60) cnt++;

        }
        return cnt;
    }
};