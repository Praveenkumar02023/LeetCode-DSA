class DisjointSet {
private:
    std::vector<int> parent, size;

public:
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
        return parent[node] = findUltimateParent(parent[node]); // Path compression
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMail;
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mapMail.find(mail) == mapMail.end()) {
                    mapMail[mail] = i;
                } else {
                    ds.unionBySize(i, mapMail[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

      for(auto it: mapMail){

        string mail = it.first;
        int node = ds.findUltimateParent(it.second);
        mergedMail[node].push_back(mail);
      }

        vector<vector<string>> res;

        for(int i = 0; i < n ; i++){
            if(mergedMail[i].size() == 0) continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMail[i].begin() , mergedMail[i].end());

            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }

        return res;
    }
};