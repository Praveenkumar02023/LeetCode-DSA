class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       
        vector<pair<int,double>> adj[n];
       
       
        for(int i = 0; i < edges.size() ; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            double wt = succProb[i];
       
            adj[from].push_back({to,wt});
             adj[to].push_back({from,wt});
        
        }

        
        vector<double> maxProb(n,0.0);
        
        maxProb[start_node] = 1.0;

        priority_queue<pair<double,int>> pq;

        pq.push({1.0,start_node});

        while(!pq.empty()){

            int top = pq.top().second;
            double wt = pq.top().first;
            pq.pop();


            for(auto it : adj[top]){
                int newNode = it.first;
                double nodeProb = it.second;
                if((wt * nodeProb) > maxProb[newNode]){

                    maxProb[newNode] = wt*nodeProb;
                    pq.push({maxProb[newNode],newNode});

                }

            }

        }

        return maxProb[end_node];   
    }
};