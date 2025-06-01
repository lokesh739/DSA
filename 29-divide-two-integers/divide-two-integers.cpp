class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Determine sign
        bool sign = !((dividend >= 0) ^ (divisor >= 0));

        // Convert to long long to avoid overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            quotient += (1LL << count);
            n -= (d << count);
        }

        // Clamp result to 32-bit signed integer limits
        if (quotient >= (1LL << 31)) {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? quotient : -quotient;
    }
};
