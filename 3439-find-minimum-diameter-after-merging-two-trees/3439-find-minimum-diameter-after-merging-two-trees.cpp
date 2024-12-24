class Solution {
public:
    pair<int,int> BFS(unordered_map<int,vector<int>> & adj , int start){
        int n = adj.size() + 1;
        vector<int> vis(n);

        queue<int> que;
        que.push(start);

        vis[start] = 1;
        int level = 0;
        int farthestPoint = start;
        while(!que.empty()){

            int levelSize = que.size();
            while(levelSize--){

                int topNode = que.front();
                farthestPoint = topNode;
                que.pop();

                for(auto node : adj[topNode]){
                    if(!vis[node]){
                        que.push(node);
                        vis[node] = 1;
                    }
                }
            }
            if(que.empty()) break;
            level++;
        }

        return make_pair(farthestPoint,level);
    }

    int findDiameter(unordered_map<int,vector<int>> & adj){

        auto [farthestPoint , distance] = BFS(adj,0);

        auto [otherEndPoint, diameter] = BFS(adj,farthestPoint);

        return diameter;
    }

    unordered_map<int,vector<int>> adjBuilder(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        unordered_map<int,vector<int>> adj1 = adjBuilder(edges1);
        unordered_map<int,vector<int>> adj2 = adjBuilder(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combinedDiameter = (d1+1)/2 + (d2+1)/2 + 1;
        return max({d1,d2,combinedDiameter});
    }
};