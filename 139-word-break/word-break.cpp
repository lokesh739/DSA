class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size=s.size();
        vector<bool> dp(size+1,false);
        dp[size]=true;

        for(int i=size-1;i>=0;i--){
            for(auto &word:wordDict){
                int j=word.size();
                if(size-i>=j && s.substr(i,j)==word && dp[i+j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};