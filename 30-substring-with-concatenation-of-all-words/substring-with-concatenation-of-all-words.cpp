class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int m = words.size();
        if (m == 0) return result;
        int len = words[0].size();
        int total_len = m * len;
        if (n < total_len) return result;
        
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        
        for (int i = 0; i < len; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> current_count;
            int count = 0;
            while (right + len <= n) {
                string w = s.substr(right, len);
                right += len;
                if (word_count.find(w) != word_count.end()) {
                    current_count[w]++;
                    count++;
                    while (current_count[w] > word_count[w]) {
                        string left_word = s.substr(left, len);
                        current_count[left_word]--;
                        count--;
                        left += len;
                    }
                    if (count == m) {
                        result.push_back(left);
                        string left_word = s.substr(left, len);
                        current_count[left_word]--;
                        count--;
                        left += len;
                    }
                } else {
                    current_count.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};