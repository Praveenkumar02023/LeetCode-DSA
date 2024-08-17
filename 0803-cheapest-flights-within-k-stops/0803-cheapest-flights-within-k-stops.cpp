class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto list : flights){

            int from = list[0];
            int to = list[1];
            int wt = list[2];

            adj[from].push_back({to,wt});
        }

        vector<int> price(n,1e9+7);

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{src,0}});

        price[src] = 0;

        while(!pq.empty()){

            int node = pq.top().second.first;
            int cost = pq.top().second.second;
            int stops = pq.top().first;
            pq.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adj_node = it.first;
                int next_cost = it.second;

                if(cost + next_cost < price[adj_node]){

                    price[adj_node] = cost + next_cost;
                    pq.push({stops+1,{adj_node,price[adj_node]}});
                }

            }
        }
        int res = price[dst];
        if(res == 1e9+7) return -1;

        return res;
    }
};