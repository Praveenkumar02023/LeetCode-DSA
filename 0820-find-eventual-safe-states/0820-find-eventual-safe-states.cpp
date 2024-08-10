class Solution {
    private: 
    bool dfs(int node , vector<int>& vis , vector<int>& pathVis , vector<int>& check,vector<vector<int>>& graph){

        vis[node] = 1;
        pathVis[node] = 1;
       

        for(auto child : graph[node]){

            if(!vis[child]){
                if(dfs(child,vis,pathVis,check,graph)){
                   
                    return true;
                }
            }else if(pathVis[child] == 1){
                return true;
            }

        }

        check[node]  = 1;
        pathVis[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        // vector<vector<int>> graphRev(V);
        // vector<int> inDegree(V);

        // for(int i = 0 ; i < V ; i++){

        //     for(auto it : graph[i]){
        //         graphRev[it].push_back(i);
        //         inDegree[i]++;
        //     }

        // }

        // queue<int> q;

        // for(int i = 0 ; i < V ; i++){

        //     if(inDegree[i] == 0) q.push(i);

        // }

        // vector<int> safeNodes;
        // while(!q.empty()){

        //     int front = q.front();
        //     q.pop();
        //     safeNodes.push_back(front);

        //     for(auto child: graphRev[front]){

        //         inDegree[child]--;

        //         if(inDegree[child] == 0 ) q.push(child);
        //     }

        // }

        // sort(safeNodes.begin() ,safeNodes.end());
        // return safeNodes;
        vector<int> vis(V,0);      
        vector<int> pathVis(V,0);      
        vector<int> check(V,0);      

        for(int i = 0 ; i < V ; i++){

            if(!vis[i]) dfs(i , vis , pathVis , check , graph);
        }

        vector<int> res;

        for(int i = 0 ; i < V ; i++){
            if(check[i]) res.push_back(i);
        }

        return res;
    }
};