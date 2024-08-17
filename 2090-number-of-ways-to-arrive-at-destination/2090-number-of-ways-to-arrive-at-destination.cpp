class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        const int mod = 1e9+7;
        for(auto list : roads){

            int u = list[0];
            int v = list[1];
            int w = list[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long > dist(n,LLONG_MAX) ; 
        vector<int> ways(n,0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0]  = 1;

        while(!pq.empty()){

            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            if (dis > dist[node]) continue; 
            
            for(auto it : adj[node]){

                int adj_node = it.first;
                int next_dis = it.second;

                
                if(next_dis + dis < dist[adj_node]){

                    pq.push({next_dis + dis,adj_node});
                    dist[adj_node] = next_dis + dis;
                    ways[adj_node] = ways[node];

                }else if(next_dis + dis == dist[adj_node]){
                   
                    ways[adj_node] = ( ways[adj_node] + ways[node] )% mod;
                }
            }
        }

        return ways[n-1] ;
    }
};