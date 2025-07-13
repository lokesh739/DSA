class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n-1 && c == n-1) return d;

            for (int i = 0; i < 8; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && d+1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = d+1;
                    q.push({d+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
