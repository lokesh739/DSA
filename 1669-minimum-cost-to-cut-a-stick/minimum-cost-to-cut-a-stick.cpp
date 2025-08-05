/*class Solution {
private:
int generate(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini=INT_MAX;
    int costs;
    for(int index=i;index<=j;index++){
        costs=cuts[j+1]-cuts[i-1]+generate(i,index-1,cuts,dp)+generate(index+1,j,cuts,dp);
        mini=min(mini,costs);
    }
    return dp[i][j]=mini;
}
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

        return generate(1,c,cuts,dp);
    }
};
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));

        int costs;
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                int mini=INT_MAX;
                if(i>j) continue;
                for(int k=i;k<=j;k++){
                    costs=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,costs);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};