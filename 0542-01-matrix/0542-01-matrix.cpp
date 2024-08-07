class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n ; i++){

            for(int j = 0 ; j < m ; j++){

                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j} , 0});
                }

            }

        }

        vector<int> rowPossibleChanges = {0,-1,0,1};
        vector<int> colPossibleChanges = {1,0,-1,0};

        while(!q.empty()){

            int idx_i = q.front().first.first;
            int idx_j = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            dis[idx_i][idx_j] = dist;

            for(int i = 0 ; i < 4 ; i++){

                int possRow = idx_i + rowPossibleChanges[i];
                int possCol = idx_j + colPossibleChanges[i];

                if(possRow >= 0 && possRow < n && possCol >= 0 && possCol < m && vis[possRow][possCol] == 0){
                    vis[possRow][possCol] = 1;
                    q.push({{possRow,possCol},dist+1});
                }
            }

        }

        return dis;
    }
};