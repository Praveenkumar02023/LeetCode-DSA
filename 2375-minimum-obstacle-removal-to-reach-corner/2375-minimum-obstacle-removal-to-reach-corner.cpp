class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push(make_pair(0,make_pair(0,0)));

        vector<int> rowChange = {1,-1,0,0};
        vector<int> colChange = {0,0,1,-1};

        while(!q.empty()){

            int curRemovedBlocks = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;

            q.pop();

            if(vis[row][col] == 1) continue;
            vis[row][col] = 1;

            if(row == n-1 && col == m-1) return curRemovedBlocks;

            for(int i = 0 ; i < 4 ; i++){
                int newRow = row + rowChange[i];
                int newCol = col + colChange[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){

                    if(grid[newRow][newCol] == 1){
                        q.push(make_pair(curRemovedBlocks + 1 , make_pair(newRow,newCol)));
                    }else{
                         q.push(make_pair(curRemovedBlocks, make_pair(newRow,newCol)));
                    }

                }
            }  
        }
        return -1;
    }
};