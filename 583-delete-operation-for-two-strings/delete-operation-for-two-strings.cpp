class Solution {
private:
    int generate(string &word1, string &word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> prev(n2+1, 0), curr(n2+1, 0); // ✅ size fixed

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = 1 + prev[j-1]; // ✅ fix: take diagonal
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;           // ✅ move current row to prev
            fill(curr.begin(), curr.end(), 0); // ✅ reset curr for next row
        }
        return prev[n2];
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int l = generate(word1, word2); // length of LCS
        return (n - l) + (m - l);       // ✅ deletions needed
    }
};
