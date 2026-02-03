class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
        if (n < 3) return false;
        
        // Precompute longest increasing sequence ending at each position
        vector<int> incFromStart(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incFromStart[i] = incFromStart[i - 1] + 1;
            } else {
                incFromStart[i] = 1;
            }
        }
        
        // Precompute longest decreasing sequence starting at each position
        vector<int> decFromStart(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                decFromStart[i] = decFromStart[i + 1] + 1;
            } else {
                decFromStart[i] = 1;
            }
        }
        
        // Precompute longest increasing sequence ending at each position from right
        vector<int> incFromEnd(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                incFromEnd[i] = incFromEnd[i + 1] + 1;
            } else {
                incFromEnd[i] = 1;
            }
        }
        
        // Try all possible p and q
        for (int p = 1; p <= n - 3; p++) {
            // Check if segment [0...p] is strictly increasing
            if (incFromStart[p] != p + 1) continue;
            
            for (int q = p + 1; q <= n - 2; q++) {
                // Check if segment [p...q] is strictly decreasing
                if (decFromStart[p] < (q - p + 1)) continue;
                
                // Check if segment [q...n-1] is strictly increasing
                if (incFromEnd[q] < (n - q)) continue;
                
                return true;
            }
        }
        
        return false;
    }
};