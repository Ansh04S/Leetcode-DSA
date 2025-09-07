class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(2 * i - n + 1);
        }
        return result;
    }
};