class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int n = str1.size(), m = str2.size();

        vector<vector<int>> t(n+1,vector<int>(m+1,0));

        for(int i = 1 ; i <= n ; i++){

            for(int j = 1 ; j <= m ; j++){

                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }

        }
        // for(int i = 0 ; i <= n ; i++){
        //     for(int j = 0 ; j <= m ; j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int i = n , j = m;
        while(i > 0 && j > 0){

            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(t[i-1][j] > t[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0){
            ans += str1[i-1];
            i--;
        }      
        while(j > 0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};