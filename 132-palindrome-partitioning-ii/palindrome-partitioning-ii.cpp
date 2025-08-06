/*class Solution {
private:
bool ispalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int generate(int i, int n, string &s, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    int cost;

    for(int j = i; j < n; j++){
        if(ispalindrome(i, j, s)){
            cost = 1 + generate(j + 1, n, s, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

public:
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return generate(0, n, s, dp) >0 ? generate(0,n,s,dp)- 1:0;
}
};
*/

class Solution {
private:
bool ispalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

public:
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1,0);
    int cost;

    for(int i=n-1;i>=0;i--){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                cost=1+dp[j+1];
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[0]>0?dp[0]-1:0;
}
};

