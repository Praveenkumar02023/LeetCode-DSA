class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(n);
        for(int i = 0 ; i < n-1 ; i++){
            adjList[i].push_back(i+1);
        }
        vector<int> res;
        

        for(auto &dir : queries ){

            int from = dir[0];
            int to = dir[1];
            vector<int> vis(n,0);
            adjList[from].push_back(to);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
            que.push(make_pair(0,0));

            while(!que.empty()){

                int node = que.top().second;
                int dist = que.top().first;

                que.pop();
                if(vis[node] == 1) continue;
                vis[node] = 1;

                if(node == n-1){
                    res.push_back(dist);
                    break;
                }

                for(auto adjNode : adjList[node]){
                   que.push(make_pair(dist + 1 , adjNode));
                }
            }


        }

        return res;

    }
};