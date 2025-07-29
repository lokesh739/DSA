/*class Solution {
private:
int generate(int index1,int index2,string &s,string &t,vector<vector<int>> &dp){
    if(index2<0) return 1;
    if(index2>0 && index1<0) return 0;

    if(dp[index1][index2]!=-1) return dp[index1][index2];

    if(s[index1]==t[index2]){
        return dp[index1][index2]=generate(index1-1,index2-1,s,t,dp) + generate(index1-1,index2,s,t,dp);
    }
    else{
        return dp[index1][index2]=generate(index1-1,index2,s,t,dp);
    }
}
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return generate(n-1,m-1,s,t,dp);
    }
};
*/

/*class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0); // ✅ use long long
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    prev[j] = prev[j-1] + prev[j]; // ✅ safe addition
                }
            }
        }
        return (int)prev[m]; // ✅ final result cast to int
    }
};
