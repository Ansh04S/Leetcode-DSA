class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long total_cost = 0;
            long long max_cost = 0;
            int k = 1;
            while (true) {
                long long low_k = (k == 1) ? 1 : (1LL << (2 * (k - 1)));
                long long high_k = (1LL << (2 * k)) - 1;
                if (low_k > r) break;
                if (high_k < l) {
                    k++;
                    continue;
                }
                long long seg_l = max(l, low_k);
                long long seg_r = min(r, high_k);
                if (seg_l <= seg_r) {
                    long long count = seg_r - seg_l + 1;
                    total_cost += k * count;
                    if (k > max_cost) max_cost = k;
                }
                k++;
            }
            long long operations = max(max_cost, (total_cost + 1) / 2);
            ans += operations;
        }
        return ans;
    }
};