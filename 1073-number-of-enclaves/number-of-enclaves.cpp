class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visi(n, vector<int>(m, 0));
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // Step 1: Push all boundary land cells into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        visi[i][j] = 1;
                    }
                }
            }
        }

        // Step 2: BFS to mark all reachable land from the boundary
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !visi[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    visi[nrow][ncol] = 1;
                }
            }
        }

        // Step 3: Count unvisited land cells (enclaves)
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visi[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
