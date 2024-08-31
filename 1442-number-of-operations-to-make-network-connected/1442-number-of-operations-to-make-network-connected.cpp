class DisjointSet {
private:
    std::vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int conComp(){

        int cnt = 0;

        for(int i =  0 ; i < parent.size()-1 ; i++){

            if(parent[i] == i){
                cnt++;
            }

        }

        return cnt;

    }

    int UltimateParent(int child) {
        if (child == parent[child]) return child;
        int ulp = UltimateParent(parent[child]);

        parent[child] = ulp;
        return parent[child];
    }

    void unionBySize(int u, int v) {
        int parU = UltimateParent(u);
        int parV = UltimateParent(v);

        if (parU == parV) return;

        if (size[parU] > size[parV]) {
            size[parU] += size[parV];
            parent[parV] = parU;
        } else if (size[parU] < size[parV]) {
            size[parV] += size[parU];
            parent[parU] = parV;
        } else {
            size[parU] += size[parV];
            parent[parV] = parU;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;
        for(auto it: connections){

            int u = it[0];
            int v = it[1];

            if(ds.UltimateParent(u) != ds.UltimateParent(v)){

                ds.unionBySize(u,v);

            }else{

                extraEdges += 1;

            }

        }

        cout<<extraEdges<<endl;

        int connectedComponent = ds.conComp();
        cout<<connectedComponent<<endl;

        if(extraEdges >= connectedComponent-1) return connectedComponent - 1;

        return -1;
    }
};