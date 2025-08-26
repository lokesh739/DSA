class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char,int> mpp;
        for(char c : s) {
            mpp[c]++;
        }

        // Move into vector of pairs
        vector<pair<char,int>> vec(mpp.begin(), mpp.end());

        // Sort by frequency descending
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;  // strictly ">" not ">="
        });

        // Build result string
        string ans;
        for(auto &p : vec) {
            ans.append(p.second, p.first); // repeat char p.second times
        }

        return ans;
    }
};