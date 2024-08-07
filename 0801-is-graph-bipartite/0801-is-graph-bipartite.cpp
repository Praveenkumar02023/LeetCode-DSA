class Solution {
public:
void bfs(int root,vector<int>& vis, vector<vector<int>>& graph){
    
     queue<pair<int,int>>q;

        q.push({root,-1});
       
        
        while(!q.empty()){
            int node =  q.front().first;
            int parent =  q.front().second;
            q.pop();
            if(parent == -1) vis[node] = 1;

            else if(vis[parent] == 1 ) vis[node] = 2;
            else vis[node] = 1;

            for(auto child : graph[node]){

                if(vis[child] == 0){
                    q.push({child,node});
                }

            }
           
        }
}
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> vis(graph.size() , 0);

        for(int i = 0 ; i < graph.size() ; i++){

            for(auto child: graph[i]){

                if(!vis[child]) bfs(child,vis,graph);

            }
        }
       

        for(int i = 0; i < graph.size() ; i++){
            int parCol = vis[i];

            for(auto child : graph[i]){
                    if(vis[child] == parCol) return false;
            }
        }

        return true;
    }
};