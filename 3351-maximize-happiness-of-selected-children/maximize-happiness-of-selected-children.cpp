class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long totalHappiness = 0;
        for (int i = 0; i < k; i++) {
            long long currentHappiness = happiness[i] - i;
            
            if (currentHappiness > 0) {
                totalHappiness += currentHappiness;
            } else {
                break;
            }
        }
        
        return totalHappiness;
    }
};