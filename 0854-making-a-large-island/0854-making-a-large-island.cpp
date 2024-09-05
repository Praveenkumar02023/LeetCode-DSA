class DisjointSet {

public:
    std::vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] =
                   findUltimateParent(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int rootU = findUltimateParent(u);
        int rootV = findUltimateParent(v);

        if (rootU == rootV)
            return;

        // Union by size
        if (size[rootU] > size[rootV]) {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        } else {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        DisjointSet ds(n * m);
        vector<int> R = {1, -1, 0, 0};
        vector<int> C = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1){
                for (int k = 0; k < 4; k++) {

                    int newR = i + R[k];
                    int newC = j + C[k];

                    if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                        grid[newR][newC] == 1) {

                        ds.unionBySize(ds.findUltimateParent(newR * m + newC),
                                       ds.findUltimateParent(i * m + j));
                    }
                }

                }
            }
        }

    if(ds.size[ds.findUltimateParent(0)] == n * m) return n *m;
    
   int largestIsland = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            unordered_set<int> st;

            if (grid[i][j] == 0) {
                int localIsland = 1;

                for (int k = 0; k < 4; k++) {
                    int newR = i + R[k];
                    int newC = j + C[k];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1) {

                        if (st.find(ds.findUltimateParent(newR * m + newC)) ==
                            st.end()) {
                            int par = ds.findUltimateParent(newR * m + newC);
                            st.insert(par);
                            localIsland += ds.size[par];
                           
                        }
                    }
                }

                largestIsland = max(largestIsland,localIsland);
            }
        }
    }
   
    return largestIsland;
    }
    
};