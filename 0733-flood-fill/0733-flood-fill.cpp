class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        int target = image[sr][sc];
        q.push({sr,sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        vector<int> rowAdj = {0,-1,0,1};
        vector<int> colAdj = {1,0,-1,0};


        while(!q.empty()){

            auto front = q.front();
            q.pop();

            int last_i = front.first;
            int last_j = front.second;

            for(int i = 0 ; i < 4 ; i++){
                int rowComb = last_i + rowAdj[i];
                int colComb = last_j + colAdj[i];

                if(rowComb >= 0 && rowComb < n && colComb >= 0 && colComb < m && vis[rowComb][colComb] == 0 && image[rowComb][colComb]  == target){

                    vis[rowComb][colComb] = 1;
                    image[rowComb][colComb] = color;
                    q.push({rowComb,colComb});
                }

            }



        }

        return image;
    }
};