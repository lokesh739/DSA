class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                min += 1;
                max += 1;
            } else if (s[i] == ')') {
                min -= 1;
                max -= 1;
            } else { // '*'
                min -= 1;
                max += 1;
            }

            if (max < 0) return false; // too many ')'
            if (min < 0) min = 0;      // clamp min to 0
        }
        return (min == 0);
    }
};
