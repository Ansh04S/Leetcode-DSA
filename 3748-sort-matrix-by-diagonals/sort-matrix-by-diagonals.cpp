class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, vector<int>> diagonals;
        
        // Group elements by their diagonal index (i - j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                diagonals[d].push_back(grid[i][j]);
            }
        }
        
        // Sort each diagonal: for d>=0 non-increasing, for d<0 non-decreasing
        for (auto &entry : diagonals) {
            int d = entry.first;
            if (d >= 0) {
                sort(entry.second.begin(), entry.second.end(), greater<int>());
            } else {
                sort(entry.second.begin(), entry.second.end());
            }
        }
        
        // Create a new matrix to place the sorted diagonals
        vector<vector<int>> result(n, vector<int>(n));


        map<int, int> indices;
        for (auto &entry : diagonals) {
            indices[entry.first] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                result[i][j] = diagonals[d][indices[d]++];
            }
        }
        
        return result;

    }
};