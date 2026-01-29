class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));
        
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < 26; j++) {
                    if (dist[k][j] == INF) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        long long totalCost = 0;
        int n = source.size();
        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (u == v) continue;
            
            if (dist[u][v] == INF) {
                return -1;
            }
            totalCost += dist[u][v];
        }
        
        return totalCost;
    }
};