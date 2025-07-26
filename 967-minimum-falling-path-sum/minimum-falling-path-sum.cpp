class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(n,0),curr(n,0);
        // Base case
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        // Tabulation
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];

                int ld = INT_MAX;
                if (j - 1 >= 0) ld = matrix[i][j] + prev[j - 1];

                int rd = INT_MAX;
                if (j + 1 < m) rd = matrix[i][j] + prev[j + 1];

                curr[j] = min(up, min(ld, rd));
            }
            prev=curr;
        }

        // Find minimum in last row
        int mini = prev[0];
        for (int j = 1; j < m; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};
