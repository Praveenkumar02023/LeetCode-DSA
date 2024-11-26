class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> res(m,vector<char>(n));

        for (auto &row : box) {

            int stone = -1;
            bool obstacle = false;
            for (int j = 0; j < m; j++) {

                if (row[j] == '#') {

                    stone = j;
                    int space = j + 1;
                    while (space < m) {
                        if (row[space] == '.') {
                            swap(row[stone], row[space]);
                            break;
                        } else if (row[space] == '*') {
                            obstacle = true;
                            break;
                        }
                        space += 1;
                    }
                  
                }
            }
        }

        for(int col = 0 ; col < m ; col++){
            for(int row = n-1; row >= 0 ; row--){
                res[col][n-1-row] = box[row][col];
            }
        }
      
    


        return res;
    }
};