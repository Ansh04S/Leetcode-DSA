class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
         for (long long k = 1; k <= 100; k++) {
            long long S = num1 - static_cast<long long>(num2) * k;
            if (S < 0) continue;
            int bits = __builtin_popcountll(S);
            if (bits <= k && k <= S) {
                return k;
            }
        }
        return -1;
    }
};