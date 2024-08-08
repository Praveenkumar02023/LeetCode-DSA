class Solution {
public:
bool bfs(int root,vector<int>& vis, vector<vector<int>>& graph){
    
     queue<int>q;

        q.push(root);
        vis[root] = 1;
        
        while(!q.empty()){
            int node =  q.front();
          
            q.pop();

            for(auto child : graph[node]){

                if(vis[child] == 0){
                    q.push(child);
                   vis[child] = 3 - vis[node];
                }else if(vis[child] == vis[node]) return false;

            }
           
        }

        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> vis(graph.size() , 0);

        for(int i = 0 ; i < graph.size() ; i++){

            for(auto child: graph[i]){

                if(!vis[child]){
                   if( bfs(child,vis,graph) == false) return false;;
                }

            }
        }
       

        return true;
    }
};