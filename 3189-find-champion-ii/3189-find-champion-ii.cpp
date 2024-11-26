class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> vis(n,0);
        for(auto &dir: edges){
            int from = dir[0];
            int to = dir[1];
            adjList[from].push_back(to);
            vis[to] = 1;
        }

        int cnt = 0;
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
            cnt += 1;
            ans = i;
            }
            if(cnt > 1) return -1; 
        }
       
        return ans;

    }
};