class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Rearrange the array using cycle sort
        for (int i = 0; i < n; i++) {
            // Keep swapping until the current element is in its correct position
            // or the current element is out of range [1, n]
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all numbers 1..n are present
        return n + 1;
    }
};