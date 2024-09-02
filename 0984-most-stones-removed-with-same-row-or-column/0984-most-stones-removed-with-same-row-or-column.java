class DisjointSet {
    private ArrayList<Integer> parent, size;

    DisjointSet(int n) {
        parent = new ArrayList<>(n + 1);
        size = new ArrayList<>(n + 1);

        for (int i = 0; i <= n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    int UltimateParent(int child) {
        if (child == parent.get(child)) return child;
        int ulp = UltimateParent(parent.get(child));
        parent.set(child, ulp);  // Path compression
        return ulp;
    }

    void unionBySize(int u, int v) {
        int parU = UltimateParent(u);
        int parV = UltimateParent(v);

        if (parU == parV) return;

        if (size.get(parU) > size.get(parV)) {
            size.set(parU, size.get(parU) + size.get(parV));
            parent.set(parV, parU);
        } else {
            size.set(parV, size.get(parV) + size.get(parU));
            parent.set(parU, parV);
        }
    }
}

class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int maxRow = 0;
        int maxCol = 0;

        for (int[] stone : stones) {
            maxRow = Math.max(maxRow, stone[0]);
            maxCol = Math.max(maxCol, stone[1]);
        }

        DisjointSet ds = new DisjointSet(maxRow + maxCol + 1);
        Map<Integer, Integer> compMap = new HashMap<>();

        for (int[] stone : stones) {
            int row = stone[0];
            int col = stone[1] + maxRow + 1;

            ds.unionBySize(row, col);
            compMap.put(row, 1);
            compMap.put(col, 1);
        }

        int cnt = 0;
        for (Map.Entry<Integer, Integer> entry : compMap.entrySet()) {
            int key = entry.getKey();
            if (ds.UltimateParent(key) == key) cnt++;
        }

        return n - cnt;
    }
}