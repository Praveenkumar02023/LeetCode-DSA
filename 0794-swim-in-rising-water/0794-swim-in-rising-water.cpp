class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

            int n = grid.size();
            int m = grid[0].size();

            priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

            vector<vector<int>> vis(n,vector<int>(m,0));

            vis[0][0] = 1;
           

            pq.push({grid[0][0],{0,0}});

            vector<int> R = {1,-1,0,0};
            vector<int> C = {0,0,1,-1};

            int minTime = 0;

            while(!pq.empty()){

                int lastTime = pq.top().first;
                int lastR = pq.top().second.first;
                int lastC = pq.top().second.second;

                pq.pop();

                if(lastR == n-1 && lastC == m-1){
                    minTime = lastTime;
                    break;
                }


                for(int i = 0; i < 4 ; i++){

                    int newR = lastR + R[i];
                    int newC = lastC + C[i];

                    if(newR >= 0 && newR < n && newC >= 0 && newC < m && vis[newR][newC] != 1){
                        vis[newR][newC] = 1;
                       
                        pq.push({max(lastTime,grid[newR][newC]),{newR,newC}});
                        
                    }
                }

            }
        return minTime;
    }
};