class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < n; ++i) {
            long long spell = spells[i];
            long long minPotion = (success + spell - 1) / spell; 
            
            if (minPotion > potions.back()) {
                pairs[i] = 0;
                continue;
            }
            
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            pairs[i] = potions.end() - it;
        }
        
        return pairs;
    }
};