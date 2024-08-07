class Solution {
public:
    void bfs(int i , int j , vector<vector<int>>& vis,vector<int>& possRow , vector<int>& possCol,vector<vector<char>>& board){
        
        vis[i][j] = 1;

        for(int k = 0 ; k < 4 ; k++){

            int nrow = i + possRow[k];
            int ncol = j + possCol[k];

            if(nrow >= 0 && nrow < vis.size() && ncol >= 0 && ncol < vis[0].size() && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
               
                bfs(nrow,ncol,vis,possRow,possCol,board);
            }
        }


    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> possRow = {0,-1,0,1};
        vector<int> possCol = {1,0,-1,0};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if((i == 0 || i == n-1 || j == 0 || j == m-1 ) && board[i][j] == 'O'){
                    bfs(i,j,vis,possRow,possCol,board);
                }

            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

               if(vis[i][j] == 0 && board[i][j] == 'O'){
                board[i][j] = 'X';
               }

            }
        }


    }
};