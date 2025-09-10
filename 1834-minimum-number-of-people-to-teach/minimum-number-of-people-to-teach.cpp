class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
       int m = languages.size();

        // Step 1: Convert each user's languages to a set for fast lookup
        vector<unordered_set<int>> langSet(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                langSet[i + 1].insert(l);
            }
        }

        // Step 2: Identify problematic friendships
        unordered_set<int> problematicUsers;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int l : langSet[u]) {
                if (langSet[v].count(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
            }
        }

        if (problematicUsers.empty()) return 0; // Everyone already communicates

        // Step 3: For each language, count how many problematic users already know it
        vector<int> langCount(n + 1, 0);
        for (int u : problematicUsers) {
            for (int l : langSet[u]) {
                langCount[l]++;
            }
        }

        // Step 4: Find minimum users to teach
        int total = problematicUsers.size();
        int best = INT_MAX;
        for (int l = 1; l <= n; l++) {
            best = min(best, total - langCount[l]);
        }

        return best;
    }
};