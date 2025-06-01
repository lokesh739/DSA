class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // 1. skip leading spaces
        while (i < n && s[i] == ' ') ++i;

        // 2. read optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        // 3. convert, checking overflow *before* it happens
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int d = s[i++] - '0';

            // If next step would overflow 32-bit, clamp and return
            if (result > (INT_MAX - d) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + d;
        }
        return result * sign;
    }
};
