class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &visi, vector<vector<char>> &grid, int delrow[], int delcol[]) {
        visi[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visi[nrow][ncol] && grid[nrow][ncol] == '1') {
                    visi[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visi(n, vector<int>(m, 0));
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visi[i][j]) {
                    bfs(i, j, visi, grid, delrow, delcol);
                    count++;
                }
            }
        }
        return count;
    }
};
