class Solution {
public:
    bool doesAliceWin(string s) {
     int n = s.length();
        long long even = 1; 
        long long odd = 0;
        int current = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                current++;
            }
            if (current % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return (even > 0 && odd > 0);
    }
};