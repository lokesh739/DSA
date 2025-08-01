/*class Solution {
private:
int generate(int index,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(index==n || cap==0) return 0;
    if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];

    int profit=0;
    if(buy){
        profit=max(-prices[index]+generate(index+1,0,cap,prices,n,dp),generate(index+1,1,cap,prices,n,dp));
    }
    else{
        profit=max(prices[index]+generate(index+1,1,cap-1,prices,n,dp),generate(index+1,0,cap,prices,n,dp));
    }
    return dp[index][buy][cap]=profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return generate(0,1,2,prices,n,dp);
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[n][buy][cap] = 0; 
            }
        }

        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
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

        return dp[0][1][2];
    }
};
