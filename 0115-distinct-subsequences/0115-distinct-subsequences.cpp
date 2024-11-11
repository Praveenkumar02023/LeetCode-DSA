class Solution {
public:
    int noOfDist(int i,int j ,string &s , string &t, int n , int m,vector<vector<int>> & mem){
            if(j == m) return 1;
            if(i == n) return 0;

            if(mem[i][j] != -1) return mem[i][j];

            int take = 0;
            if(s[i] == t[j]) take = noOfDist(i+1,j+1,s,t,n,m,mem);

            int notTake = noOfDist(i+1,j,s,t,n,m,mem);

            return mem[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> mem(n+1,vector<int>(m+1,-1));    

        
        return noOfDist(0,0,s,t,n,m,mem);
    }
};