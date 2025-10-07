class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
    vector<int> ans(n, -1);
    unordered_map<int, int> lastRain; 
    set<int> dryDays; 

    for (int i = 0; i < n; i++) {
        if (rains[i] == 0) {
            dryDays.insert(i);
            ans[i] = 1; 
        } else {
            int lake = rains[i];
            if (lastRain.count(lake)) {
                int lastDay = lastRain[lake];
                auto it = dryDays.upper_bound(lastDay);
                if (it == dryDays.end()) {
                    return {}; 
                }
                int dryDay = *it;
                ans[dryDay] = lake;
                dryDays.erase(dryDay);
            }
            lastRain[lake] = i;
        }
    }
    return ans;
    }
};