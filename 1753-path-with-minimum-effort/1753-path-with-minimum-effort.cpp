class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(n,vector<int>(m , INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        vector<int> rowChange = { 1 , -1 , 0 , 0};
        vector<int> colChange = { 0 , 0 , 1 , -1};

        while(!pq.empty()){

            int row = pq.top().second.first;
            int col = pq.top().second.second;

            int effort = pq.top().first;
            pq.pop();

            for(int i = 0 ; i < 4 ; i++){
                int newRow = row + rowChange[i];
                int newCol = col + colChange[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ){


                int newEffort = max(abs(heights[newRow][newCol] - heights[row][col]),effort);
                    
                      if( dist[newRow][newCol] > newEffort){

                        dist[newRow][newCol]  = newEffort;
                        pq.push({newEffort,{newRow,newCol}});                  
                      }
                }

            }
        }

        return dist[n-1][m-1];
    }
};