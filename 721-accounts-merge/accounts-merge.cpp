class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findultimateparent(int x) {
        if(x == parent[x]) return x;
        return parent[x] = findultimateparent(parent[x]);
    }

    bool find(int u, int v) {
        return findultimateparent(u) == findultimateparent(v);
    }

    void unionByRank(int u, int v) {
        int ulu = findultimateparent(u);
        int ulv = findultimateparent(v);
        if(ulu == ulv) return;
        if(rank[ulu] < rank[ulv]) {
            parent[ulu] = ulv;
        } else if(rank[ulv] < rank[ulu]) {
            parent[ulv] = ulu;
        } else {
            parent[ulu] = ulv;
            rank[ulv]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulu = findultimateparent(u);
        int ulv = findultimateparent(v);
        if(ulu == ulv) return;
        if(size[ulu] < size[ulv]) {
            parent[ulu] = ulv;
            size[ulv] += size[ulu];
        } else {
            parent[ulv] = ulu;
            size[ulu] += size[ulv];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto& it : mapMailNode) {
            string mail = it.first;
            int node = ds.findultimateparent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
