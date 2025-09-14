class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;
        
        for (const string& word : wordlist) {
            exactMatch.insert(word);
            
            string lowerWord = toLower(word);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end()) {
                caseInsensitive[lowerWord] = word;
            }
            
            string devoweled = devowel(lowerWord);
            if (vowelInsensitive.find(devoweled) == vowelInsensitive.end()) {
                vowelInsensitive[devoweled] = word;
            }
        }
        
        vector<string> result;
        for (const string& query : queries) {
            if (exactMatch.find(query) != exactMatch.end()) {
                result.push_back(query);
                continue;
            }
            
            string lowerQuery = toLower(query);
            if (caseInsensitive.find(lowerQuery) != caseInsensitive.end()) {
                result.push_back(caseInsensitive[lowerQuery]);
                continue;
            }
            
            string devoweledQuery = devowel(lowerQuery);
            if (vowelInsensitive.find(devoweledQuery) != vowelInsensitive.end()) {
                result.push_back(vowelInsensitive[devoweledQuery]);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
    
private:
    string toLower(const string& s) {
        string result;
        for (char c : s) {
            result += tolower(c);
        }
        return result;
    }
    
    string devowel(const string& s) {
        string result;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                result += '*';
            } else {
                result += c;
            }
        }
        return result;
    }
};