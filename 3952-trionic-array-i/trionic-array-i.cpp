class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
        if (n < 3) return false;
        
        vector<int> incFromStart(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incFromStart[i] = incFromStart[i - 1] + 1;
            } else {
                incFromStart[i] = 1;
            }
        }
        
        vector<int> decFromStart(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                decFromStart[i] = decFromStart[i + 1] + 1;
            } else {
                decFromStart[i] = 1;
            }
        }
        
        vector<int> incFromEnd(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                incFromEnd[i] = incFromEnd[i + 1] + 1;
            } else {
                incFromEnd[i] = 1;
            }
        }
        
        for (int p = 1; p <= n - 3; p++) {
            if (incFromStart[p] != p + 1) continue;
            
            for (int q = p + 1; q <= n - 2; q++) {

                if (decFromStart[p] < (q - p + 1)) continue;
            
                if (incFromEnd[q] < (n - q)) continue;
                
                return true;
            }
        }
        
        return false;
    }
};