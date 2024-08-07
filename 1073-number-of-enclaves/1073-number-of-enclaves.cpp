class Solution {
public:
void dfs(int i , int j , vector<vector<int>> & vis , vector<vector<int>>& grid , vector<int>& possRow , vector<int>& possCol){
int n = grid.size();
int m = grid[0].size();

vis[i][j] = 1;

for(int k = 0 ; k < 4 ; k++){

    int nrow = i + possRow[k];
    int ncol = j + possCol[k];


    if(nrow >= 0 && nrow < n && ncol >=  0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
        dfs(nrow,ncol,vis,grid,possRow,possCol);
    }

}

}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        vector<int> possRow = {0,-1,0,1};
        vector<int> possCol = {1,0,-1,0};

        for(int j = 0 ; j < m ; j++){

            if(vis[0][j] == 0 && grid[0][j] == 1){
                dfs(0,j,vis,grid,possRow,possCol);
            }

            if(vis[n-1][j] == 0 && grid[n-1][j] == 1){
                dfs(n-1,j,vis,grid,possRow,possCol);
            }

        }
        
        for(int i = 0 ; i < n ; i++){

            if(vis[i][0] == 0 && grid[i][0] == 1){
                dfs(i,0,vis,grid,possRow,possCol);
            }

            if(vis[i][m-1] == 0 && grid[i][m-1] == 1){
                dfs(i,m-1,vis,grid,possRow,possCol);
            }

        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(vis[i][j] == 0 && grid[i][j] == 1) cnt += 1;

            }
        }

        return cnt;
    }
};