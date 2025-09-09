class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n+1, 0);
        vector<long long> prefix(n+1, 0);
        dp[1] = 1;
        prefix[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int l = max(1, i - forget + 1);
            int r = i - delay;
            if (r < 1) {
                dp[i] = 0;
            } else {
                l = max(1, l);
                r = max(0, r); // but r is at least 1 here
                long long sum = (prefix[r] - prefix[l-1] + MOD) % MOD;
                dp[i] = sum;
            }
            prefix[i] = (prefix[i-1] + dp[i]) % MOD;
        }
        
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i + forget > n) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        return ans;
    }
};