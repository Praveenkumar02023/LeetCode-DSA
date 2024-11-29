class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1; 

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push(make_pair(0,make_pair(0,0)));
        vector<int> rowChange = {1,0,-1,0};
        vector<int> colChange = {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));

        while(!pq.empty()){

            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();
            if(vis[row][col] == 1) continue;
            vis[row][col] = 1;
            if(row == n-1 && col == m-1) return time;

            for(int i = 0 ; i < 4 ; i++){
                int newRow = row + rowChange[i];
                int newCol = col + colChange[i];

                if(newRow < n && newCol < m && newRow >= 0 && newCol >= 0){
                    if(grid[newRow][newCol] <= time + 1){
                        pq.push(make_pair(time + 1 , make_pair(newRow,newCol)));
                    }else{
                        int timeDiff = grid[newRow][newCol] - time;
                        if(timeDiff % 2 == 0)
                         pq.push(make_pair(grid[newRow][newCol] + 1 , make_pair(newRow,newCol)));
                        else  pq.push(make_pair( grid[newRow][newCol], make_pair(newRow,newCol)));  
                    }
                }
            }

       
        }
         return -1;
    }
};