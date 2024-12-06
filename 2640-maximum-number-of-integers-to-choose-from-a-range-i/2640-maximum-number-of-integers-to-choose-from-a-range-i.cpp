class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(),banned.end());

        int i = 1 , j = 1;

        int maxNum = 0;
        int curSum = 0;
        int curNum = 0;
        while(j < n+1){

           if(st.find(j) == st.end()){
            curSum += j;
            curNum += 1;
           }

           while(curSum > maxSum){
            if(st.find(i) == st.end()){
                curSum -= i;
                curNum -= 1; 
            }
            i++;
           }
           
           maxNum = max(maxNum,curNum);
            
            j++;
        }

        return maxNum;
    }
};