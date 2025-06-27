class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string ans=q.front().first;
            int step=q.front().second;
            q.pop();

            if(ans==endWord) return step;
            for(int i=0;i<ans.length();i++){
                char original=ans[i];
                for(char ch='a';ch<='z';ch++){
                    ans[i]=ch;
                    if(st.find(ans)!=st.end()){
                        st.erase(ans);
                        q.push({ans,step+1});
                    }
                }
                ans[i]=original;
            }
        }
        return 0;
    }
};