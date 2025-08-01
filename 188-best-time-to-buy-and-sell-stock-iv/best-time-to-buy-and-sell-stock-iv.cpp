/*class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= k; cap++) {
                dp[n][buy][cap] = 0; 
            }
        }

        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[index] + dp[index+1][0][cap],
                                     dp[index+1][1][cap]);
                    } else {
                        profit = max(prices[index] + dp[index+1][1][cap-1],
                                     dp[index+1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};
*/

/*class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = 2*k-1; j >= 0; j--) {

                if (j % 2 == 0) { // Buy state
                    int take = (j+1 <= 2*k-1) ? -prices[i] + dp[i+1][j+1] : -prices[i];
                    dp[i][j] = max(take, dp[i+1][j]);
                } 
                else { // Sell state
                    int take = (j+1 <= 2*k-1) ? prices[i] + dp[i+1][j+1] : prices[i];
                    dp[i][j] = max(take, dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> ahead(2*k+1, 0), curr(2*k+1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int j = 2*k-1; j >= 0; j--) {
                if (j % 2 == 0) // Buy
                    curr[j] = max(-prices[i] + ahead[j+1], ahead[j]);
                else // Sell
                    curr[j] = max(prices[i] + ahead[j+1], ahead[j]);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

