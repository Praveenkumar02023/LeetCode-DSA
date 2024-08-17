class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto list : times){

            int from = list[0];
            int to = list[1];
            int time = list[2];

            adj[from].push_back({to,time});
        }


        vector<int> time(n+1,1e9+7);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});

        time[k] = 0;

        while(!pq.empty()){

            int node = pq.top().second;
            int tm = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int adj_node = it.first;
                int next_time = it.second;

                if(tm + next_time < time[adj_node]){

                    time[adj_node] = tm + next_time;
                    pq.push({time[adj_node],adj_node});
                }
 
            }

        }        

        int res = 0;

        for(int i = 1 ; i <= n ; i++ ){
            res = max(res,time[i]);
        }

        if(res == 1e9+7) return -1;

        return res;

    }
};