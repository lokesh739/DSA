class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjlist, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjlist[node]) {
            if (!visited[it]) {
                dfs(it, adjlist, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);      // ✅ Correct dynamic allocation
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);  // ✅ Undirected edge
                }
            }
        }

        vector<int> visited(n, 0);  // ✅ Use vector instead of C-style array
        int count = 0;
        for (int i = 0; i < n; ++i) {  // ✅ Start from 0, not 1
            if (!visited[i]) {
                count++;
                dfs(i, adjlist, visited);
            }
        }

        return count;
    }
};
