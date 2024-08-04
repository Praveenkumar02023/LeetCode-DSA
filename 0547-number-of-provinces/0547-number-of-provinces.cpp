class Solution {
public:
    void dfs(int node, vector<int>& vis,vector<vector<int>>& con ){
        vis[node] = 1;

        for(int i = 0 ; i < con[0].size() ; i++){
            if(con[node-1][i] == 1 && vis[i+1] == 0 ){
                vis[i+1] = 1;
                dfs(i+1,vis,con);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size()+1,0);

        int cnt  = 0;
       
       for(int i = 1 ; i < vis.size() ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
       }

        return cnt;
    }
};