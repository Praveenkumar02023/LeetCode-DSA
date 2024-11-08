class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin() , temp.end());

        int n = s.size();

        vector<int> curRow(n+1,0) , prev(n+1,0);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){

                if(s[i-1] == temp[j-1]){
                    curRow[j] = 1 + prev[j-1];
                }else{
                    curRow[j] = max(prev[j],curRow[j-1]);
                }
            }
            prev = curRow;
        }

    //    for(int i = 0 ; i <= n ; i++){
    //     cout<<cur
    //    }

        return curRow[n];
    }
};