class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxSize = min(m, n);
        
        vector<vector<int>> rowPref(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> colPref(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPref[i + 1][j + 1] = rowPref[i + 1][j] + grid[i][j];
                colPref[i + 1][j + 1] = colPref[i][j + 1] + grid[i][j];
            }
        }
        
        auto getRowSum = [&](int r, int c1, int c2) {
            return rowPref[r + 1][c2 + 1] - rowPref[r + 1][c1];
        };
        
        auto getColSum = [&](int c, int r1, int r2) {
            return colPref[r2 + 1][c + 1] - colPref[r1][c + 1];
        };
        
        for (int k = maxSize; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    
                    int diag1 = 0, diag2 = 0;
                    for (int d = 0; d < k; d++) {
                        diag1 += grid[i + d][j + d];
                        diag2 += grid[i + d][j + k - 1 - d];
                    }
                    
                    int target = diag1;
                    if (diag2 != target) continue;
                    
                    bool valid = true;
                    
                    for (int r = i; r < i + k; r++) {
                        if (getRowSum(r, j, j + k - 1) != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;
                    for (int c = j; c < j + k; c++) {
                        if (getColSum(c, i, i + k - 1) != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;
                    return k;
                }
            }
        }
        
        return 1;
    }
};