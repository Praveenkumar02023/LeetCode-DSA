class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if( grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<pair<int,int>,int>> q;
        
        vector<vector<int>> vis(grid.size() , vector<int>(grid.size(),0));
        
        q.push({{0,0},0});
        vis[0][0] = 1;

        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            vis[i][j] = 1;

            if(i == n-1 && j == n-1) return dist+1;

            q.pop();

            if( (i+1 < n && j + 1 < n) && grid[i+1][j+1] == 0 && vis[i+1][j + 1] == 0){
               vis[i+1][j + 1] = 1;
             q.push({{i+1,j+1},dist + 1}); 
            }
           
            if( (i-1 >= 0 && j -1 > 0) && grid[i-1][j-1] == 0 && vis[i-1][j - 1] == 0) {
                vis[i-1][j - 1] = 1;
            q.push({{i-1,j-1},dist + 1}); 
            }
           
            if( (i-1 >= 0 && j + 1 < n) && grid[i-1][j+1] == 0 && vis[i-1][j + 1] == 0) {
                vis[i-1][j + 1] = 1;
            q.push({{i-1,j+1},dist + 1}); 
            }
           
            if( (i+1 < n && j - 1 > 0) && grid[i+1][j-1] == 0 && vis[i+1][j - 1] == 0){
                vis[i+1][j - 1] = 1;
             q.push({{i+1,j-1},dist + 1}); 
            }
            
            if( i+1 < n && grid[i+1][j] == 0 && vis[i+1][j] == 0){
                 vis[i+1][j] = 1;

             q.push({{i+1,j},dist + 1});
            }
            
            if( i-1 >= 0 && grid[i-1][j] == 0 && vis[i-1][j] == 0){
                 vis[i-1][j] = 1;
             q.push({{i-1,j},dist + 1});
            }
           
            if( j+1 < n && grid[i][j+1] == 0 && vis[i][j + 1] == 0) {
             vis[i][j + 1] = 1;
            q.push({{i,j+1},dist + 1});
            }

            if( j-1 >= 0 && grid[i][j-1] == 0 && vis[i][j - 1] == 0){
                vis[i][j - 1] = 1;
             q.push({{i,j-1},dist + 1});
            }

        }
        return -1;
    }
};