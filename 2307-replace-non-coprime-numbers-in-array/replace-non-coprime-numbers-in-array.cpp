class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
         stack<int> st;
        for (int num : nums) {
            int current = num;
            while (!st.empty()) {
                int top = st.top();
                int gcd_val = gcd(top, current);
                if (gcd_val > 1) {
                    current = lcm(top, current);
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(current);
        }
        
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
};