/*class Solution {
private:
int generate(int index1,int index2,string &text1,string &text2,vector<vector<int>> &dp){
    if(index1<0 || index2<0){
        return 0;
    }

    if(dp[index1][index2]!=-1) return dp[index1][index2];
    if(text1[index1]==text2[index2]){
        return dp[index1][index2]=1+generate(index1-1,index2-1,text1,text2,dp);
    }
    return dp[index1][index2]= max(generate(index1-1,index2,text1,text2,dp),generate(index1,index2-1,text1,text2,dp));
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return generate(n1-1,n2-1,text1,text2,dp);
    }
};
*/

/*class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int j=0;j<=n2;j++) dp[0][j]=0;
        for(int i=0;i<=n1;i++) dp[i][0]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);
        for(int j=0;j<=n2;j++) prev[j]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};


