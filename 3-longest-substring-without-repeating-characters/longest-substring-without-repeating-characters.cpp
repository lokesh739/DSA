class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int maxlength = 0;
        int left = 0;
        int right = 0;
        int hash[256];
        fill(hash, hash + 256, -1); // Fix: Properly initialize hash array

        while (right < n) {
            if (hash[s[right]] != -1 && hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            maxlength = max(maxlength, right - left + 1);
            right++;
        }
        return maxlength;
    }
};
