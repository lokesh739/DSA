class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> dist;

    void bfs(string& beginWord, string& endWord, unordered_set<string>& wordSet) {
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front(); q.pop();
            int d = dist[word];

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (wordSet.count(temp)) {
                        if (!dist.count(temp)) {
                            dist[temp] = d + 1;
                            q.push(temp);
                            adj[temp].push_back(word);
                        } else if (dist[temp] == d + 1) {
                            adj[temp].push_back(word);
                        }
                    }
                }
            }
        }
    }

    void dfs(string& word, string& beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        for (string& prev : adj[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        bfs(beginWord, endWord, wordSet);

        if (!dist.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return res;
    }
};
