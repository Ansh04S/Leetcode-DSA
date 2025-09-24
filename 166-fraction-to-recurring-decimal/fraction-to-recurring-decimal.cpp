class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        
        // Handle the case when numerator is 0
        if (numerator == 0) return "0";
        
        string result;
        
        // Determine the sign of the result
        if ((numerator < 0) ^ (denominator < 0)) {
            result += '-';
        }
        
        // Convert to long long to avoid integer overflow
        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));
        
        // Integer part
        result += to_string(num / den);
        num %= den;
        
        // If no fractional part, return the result
        if (num == 0) {
            return result;
        }
        
        // Fractional part
        result += '.';
        
        // Map to store remainder and its position
        unordered_map<long long, int> remainderMap;
        
        while (num != 0) {
            // If we've seen this remainder before, we have a repeating decimal
            if (remainderMap.find(num) != remainderMap.end()) {
                int pos = remainderMap[num];
                result.insert(pos, "(");
                result += ')';
                break;
            }
            
            // Store the current remainder and its position
            remainderMap[num] = result.length();
            
            // Multiply remainder by 10 for next digit
            num *= 10;
            
            // Append the quotient to result
            result += to_string(num / den);
            
            // Get next remainder
            num %= den;
        }
        
        return result;
    }
};

// Test function
void testFractionToDecimal(int numerator, int denominator, string expected) {
    Solution sol;
    string result = sol.fractionToDecimal(numerator, denominator);
    cout << numerator << " / " << denominator << " = " << result;
    if (result == expected) {
        cout << " ✓ PASS" << endl;
    } else {
        cout << " ✗ FAIL (Expected: " << expected << ")" << endl;
    }
};