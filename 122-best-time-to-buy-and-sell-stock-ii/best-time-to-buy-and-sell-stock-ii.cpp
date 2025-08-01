/*class Solution {
private:
int generate(int index,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(index==n) return 0;

    if(dp[index][buy]!=-1) return dp[index][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[index]+generate(index+1,0,prices,n,dp),generate(index+1,1,prices,n,dp));
    }
    else{
        profit=max(prices[index]+generate(index+1,1,prices,n,dp),generate(index+1,0,prices,n,dp));
    }
    return dp[index][buy]=profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return generate(0,1,prices,n,dp);
    }
};
*/

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;

        for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                } else {
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int aheadnotbuy,aheadbuy,currnotbuy,currbuy;
        aheadnotbuy=aheadbuy=0;
        

        for (int i = n-1; i >= 0; i--) {
            
            currbuy=max(-prices[i]+aheadnotbuy,aheadbuy);
            currnotbuy=max(prices[i]+aheadbuy,aheadnotbuy);

            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;
        }
        return aheadbuy;;
    }
};

