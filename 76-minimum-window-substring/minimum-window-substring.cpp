class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlength = INT_MAX;
        int l = 0;
        int r = 0;
        int hash[256] = {0};
        int rindex = -1;
        int count = 0;

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) count++;
            hash[s[r]]--;

            while (count == m) {
                if (r - l + 1 < minlength) {
                    minlength = r - l + 1;
                    rindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        if (rindex == -1) return "";
        return s.substr(rindex, minlength);
    }
};
