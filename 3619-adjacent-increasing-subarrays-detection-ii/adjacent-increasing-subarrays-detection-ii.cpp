class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
      int n = nums.size();
        int maxK = 0;
        
        vector<pair<int, int>> segments; 
        
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || nums[i] <= nums[i - 1]) {
                segments.push_back({start, i - 1});
                start = i;
            }
        }
        
        for (int i = 0; i < segments.size(); i++) {
            int len = segments[i].second - segments[i].first + 1;
            if (len >= 2) {
                maxK = max(maxK, len / 2);
            }
        
            if (i < segments.size() - 1) {
                int currentLen = segments[i].second - segments[i].first + 1;
                int nextLen = segments[i + 1].second - segments[i + 1].first + 1;
                maxK = max(maxK, min(currentLen, nextLen));
            }
        }
        
        return maxK;
    }
};