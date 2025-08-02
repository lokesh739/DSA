/*class Solution {
private:
int generate(int index,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(index>=n) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];

    int profit=0;
    if(buy){
        profit=max(-prices[index]+generate(index+1,0,prices,n,dp),generate(index+1,1,prices,n,dp));
    }
    else{
        profit=max(prices[index]+generate(index+2,1,prices,n,dp),generate(index+1,0,prices,n,dp));
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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);
        if(n==0) return 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[i]+front1[0],front1[1]);
                }
                else{
                    profit=max(prices[i]+front2[1],front1[0]);
                }
                curr[buy]=profit;
            }
            front2=front1;
            front1=curr;

        }
        return curr[1];
    }
};

