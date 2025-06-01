class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

    // (base^exp) % MOD  –– recursive binary exponentiation
    long long modPow(long long base, long long exp) const {
        if (exp == 0) return 1;
        long long half = modPow(base, exp >> 1);
        long long res  = (half * half) % MOD;
        if (exp & 1) res = (res * base) % MOD;
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenCnt = (n + 1) >> 1;               // ceil(n/2)
        long long oddCnt  =  n        >> 1;             // floor(n/2)

        long long part1 = modPow(5, evenCnt);           // 5^evenCnt
        long long part2 = modPow(4, oddCnt);            // 4^oddCnt

        return static_cast<int>((part1 * part2) % MOD);
    }
};
