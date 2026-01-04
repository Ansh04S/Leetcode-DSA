class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int totalSum = 0;
        unordered_map<int, int> memo;
        
        for (int num : nums) {
            if (memo.find(num) != memo.end()) {
                totalSum += memo[num];
                continue;
            }
            
            int divisorSum = 0;
            int divisorCount = 0;
            
            int sqrtNum = sqrt(num);
            int lastDivisor = 0;
            
            for (int i = 1; i <= sqrtNum; i++) {
                if (num % i == 0) {
                    divisorCount++;
                    divisorSum += i;
                    
                    if (i != num / i) {
                        divisorCount++;
                        divisorSum += num / i;
                    }
                
                    if (divisorCount > 4) break;
                }
            }
            
            if (divisorCount == 4) {
                memo[num] = divisorSum;
                totalSum += divisorSum;
            } else {
                memo[num] = 0;
            }
        }
        
        return totalSum;
    }
};