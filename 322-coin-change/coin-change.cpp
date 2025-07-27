class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
            else
                dp[0][t] = INT_MAX;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int nottake = dp[i - 1][target];
                int take = INT_MAX;

                if (coins[i] <= target && dp[i][target - coins[i]] != INT_MAX) {
                    take = 1 + dp[i][target - coins[i]]; // ✅ Prevent overflow
                }

                dp[i][target] = min(take, nottake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= INT_MAX) return -1;
        return ans;
    }
};
