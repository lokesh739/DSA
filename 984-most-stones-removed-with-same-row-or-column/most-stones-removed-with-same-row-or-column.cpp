class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findultimateparent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findultimateparent(parent[x]);
    }

    void unionByRank(int u, int v) {
        int pu = findultimateparent(u);
        int pv = findultimateparent(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;
        for(auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for(auto& it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1; // offset columns

            ds.unionByRank(row, col);
            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for(int node : nodes) {
            if(ds.findultimateparent(node) == node) {
                components++;
            }
        }

        return n - components;
    }
};
