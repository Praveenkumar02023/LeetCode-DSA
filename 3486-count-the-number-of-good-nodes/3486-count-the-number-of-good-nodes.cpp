
class Solution {
public:
    int dfs(int i , int &cnt ,vector<vector<int>>& adj,int parent){

        int lastSize = -1;
        bool flag = true;
        int size = 1 ;
        for(auto child : adj[i]){

            if(parent == child) continue;

            int s = dfs(child,cnt,adj,i);

            if(lastSize == -1) lastSize = s;
            else{
                if(lastSize != s) flag = false;
            }
            
            size += s;
        }

        if(flag) cnt++;
        return size;

       
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        // As V is the maximum index + 1

       int V = edges.size()+1;

        vector<vector<int>> adj(V);

        for(int i = 0;  i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
       int res = dfs(0, cnt, adj,-1);

        return cnt; 
    }
};
