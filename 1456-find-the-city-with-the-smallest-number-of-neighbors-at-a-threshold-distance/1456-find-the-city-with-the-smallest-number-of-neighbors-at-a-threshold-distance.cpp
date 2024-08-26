class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        
        vector<vector<int>> adjMat(n,vector<int>(n,1e9+7));
        for(int i = 0 ; i < n ; i++){

            adjMat[i][i] = 0;

        }

        for(auto it: edges){

            int from = it[0];
            int to = it[1];
            int wt = it[2];

            adjMat[from][to] = wt;
            adjMat[to][from] = wt;

        }


        for(int k = 0; k < n ; k++){

            for(int i = 0 ; i < n ; i++){

                for(int j = 0; j < n ; j++){

                    adjMat[i][j] = min(adjMat[i][j] , adjMat[i][k] + adjMat[k][j]);

                }

            }

        }

        vector<int> minEdges(n);

        for(int i = 0 ; i < n ; i++){

            for(int j = 0; j < n ; j++){

                if(adjMat[i][j] <= thres) minEdges[i]++;

            }

        }

        int minm = INT_MAX;
        int res = -1;

        for(int i = 0 ; i < n ; i++){

            if(minEdges[i] <= minm){
                minm = minEdges[i];
                res = i;
            }          
            
        }
        return res;
    }
};