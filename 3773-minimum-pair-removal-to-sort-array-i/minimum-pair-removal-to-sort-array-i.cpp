class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
           int operations = 0;
        int n = nums.size();
        
        auto isNonDecreasing = [&]() {
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[i-1]) return false;
            }
            return true;
        };
        
        while (!isNonDecreasing()) {
            int minSum = INT_MAX;
            int minIdx = -1;
            
            for (int i = 0; i < n - 1; i++) {
                int currentSum = nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minIdx = i;
                }
            }
            
            nums[minIdx] = minSum;
            
            for (int i = minIdx + 1; i < n - 1; i++) {
                nums[i] = nums[i+1];
            }
            n--; 
            
            operations++;
        }
        
        return operations;
    }
};