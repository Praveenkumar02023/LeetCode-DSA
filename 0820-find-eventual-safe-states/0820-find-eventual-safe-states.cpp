class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> graphRev(V);
        vector<int> inDegree(V);

        for(int i = 0 ; i < V ; i++){

            for(auto it : graph[i]){
                graphRev[it].push_back(i);
                inDegree[i]++;
            }

        }

        queue<int> q;

        for(int i = 0 ; i < V ; i++){

            if(inDegree[i] == 0) q.push(i);

        }

        vector<int> safeNodes;
        while(!q.empty()){

            int front = q.front();
            q.pop();
            safeNodes.push_back(front);

            for(auto child: graphRev[front]){

                inDegree[child]--;

                if(inDegree[child] == 0 ) q.push(child);
            }

        }

        sort(safeNodes.begin() ,safeNodes.end());
        return safeNodes;
        
    }
};