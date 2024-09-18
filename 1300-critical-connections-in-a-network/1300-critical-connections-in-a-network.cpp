class Solution {
public:
    int timer = 1;
  
  void dfs(int node , int parent , vector<int>& tin , vector<int>& low, vector<int> & vis  , vector<vector<int>>& mark,vector<vector<int>>& adj){
      
        vis[node] = 1;
        
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it : adj[node]){
            if(parent == it)continue;
         else if(!vis[it]){
            
            dfs(it,node,tin,low,vis,mark,adj);
            low[node] = min(low[node],low[it]);
            
            if(low[it] >  tin[node]){
                mark.push_back({node,it});
            }
        }
        else{
            low[node] = min(low[node],tin[it]);
        }
        
        }

  }

    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
        vector<vector<int>> adj(V);

        for(auto list : connections){
            int from = list[0];
            int to = list[1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<vector<int>> mark;
        vector<int> vis(V,0);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        
        for(int i = 0 ; i < V ; i++){
            
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,mark,adj);
            }
            
        }
        
        return mark;
    }
};