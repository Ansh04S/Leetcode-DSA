class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowelFreq;
        unordered_map<char, int> consonantFreq;
        
        for (char ch : s) {
            if (isVowel(ch)) {
                vowelFreq[ch]++;
            } else {
                consonantFreq[ch]++;
            }
        }
        
        int maxVowel = 0;
        for (auto& pair : vowelFreq) {
            if (pair.second > maxVowel) {
                maxVowel = pair.second;
            }
        }
        
        int maxConsonant = 0;
        for (auto& pair : consonantFreq) {
            if (pair.second > maxConsonant) {
                maxConsonant = pair.second;
            }
        }
        
        return maxVowel + maxConsonant;
    }
    
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    

        
    }
};