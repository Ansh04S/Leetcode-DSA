class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool box[9][10] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                if (row[i][num] || col[j][num] || box[boxIndex][num]) {
                    return false;
                }
                
                row[i][num] = true;
                col[j][num] = true;
                box[boxIndex][num] = true;
            }
        }
        return true;
    }
};