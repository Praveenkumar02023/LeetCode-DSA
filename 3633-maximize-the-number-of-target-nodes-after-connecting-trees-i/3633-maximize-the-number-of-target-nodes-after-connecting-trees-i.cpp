class Solution {
public:
    vector<int> findTargetNodesBFS(vector<vector<int>>& adjList , int k){

        int n = adjList.size();
        vector<int> possTarget(n);
        
        
       
        for(int i = 0 ; i < n ;i++){
            if (k == 0) {
                possTarget[i] = 1; // Only the node itself is reachable
                continue;
            }
            vector<int> vis(n,0);
            queue<int>q;
            q.push(i);
            vis[i] = 1;

             int level = 0;

            while(!q.empty() && level < k){

                 int size = q.size(); // Process all nodes at the current level
                for (int j = 0; j < size; j++) {
                    int curNode = q.front();
                    q.pop();

                    for (auto& adjNode : adjList[curNode]) {
                        if (!vis[adjNode]) {
                            q.push(adjNode);
                            vis[adjNode] = 1;
                        }
                    }
                }
                level++;
            }

            int targetNodeCnt = count(vis.begin(),vis.end(),1);
            possTarget[i] = targetNodeCnt;

        }
        return possTarget;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

        if(k == 0) return vector<int>(n+1,1);
        vector<vector<int>> adjList1(n+1);
        vector<vector<int>> adjList2(m+1);

        for(auto & edge : edges1){
            int u = edge[0];
            int v = edge[1];

            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }
         for(auto & edge : edges2){
            int u = edge[0];
            int v = edge[1];

            adjList2[u].push_back(v);
            adjList2[v].push_back(u);
        }

        vector<int> targetPosTree1 = findTargetNodesBFS(adjList1,k);
        vector<int> targetPosTree2 = findTargetNodesBFS(adjList2,k-1);

        int maxTargetTree2 = *max_element(targetPosTree2.begin(),targetPosTree2.end());

        vector<int> res(n+1);

        for(int i = 0 ; i < n+1 ; i++){

            res[i] = targetPosTree1[i] + maxTargetTree2;

        }

        return res;

    }
};