
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(grid.size(), vector<int>(grid.size(), 0));

        vector<int> rowChange = {1, -1, 1, -1, 1, -1, 0, 0};
        vector<int> colChange = {1, -1, -1, 1, 0, 0, 1, -1};

        q.push({{0, 0}, 0});
        vis[0][0] = 1;

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
           

            if (row == n - 1 && col == n - 1)
                return dist + 1;

            q.pop();

            for (int i = 0; i < 8; i++) {
                int newRow = row + rowChange[i];
                int newCol = col + colChange[i];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && vis[newRow][newCol] == 0) {

                    vis[newRow][newCol] = 1;
                    q.push({{newRow,newCol},dist + 1});
                }
            }
        }
        return -1;
}        
};