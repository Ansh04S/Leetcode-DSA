class Spreadsheet {
    private:
    int rows;
    vector<vector<int>> sheet; // 2D vector: rows x 26 columns

    // Helper to convert column letter to index (A -> 0, ..., Z -> 25)
    int colIndex(char col) {
        return col - 'A';
    }

    // Parse cell reference like "A1" -> pair(row, col)
    pair<int, int> parseCell(const string &cell) {
        int col = colIndex(cell[0]);
        int row = stoi(cell.substr(1)) - 1; // convert 1-indexed to 0-indexed
        return {row, col};
    }

    // Check if string is a number
    bool isNumber(const string &s) {
        for (char c : s) if (!isdigit(c)) return false;
        return true;
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        sheet.assign(rows, vector<int>(26, 0)); 
        
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        sheet[row][col] = value;
        
    }
    
    void resetCell(string cell) {
       auto [row, col] = parseCell(cell);
        sheet[row][col] = 0; 
    }
    
    int getValue(string formula) {
      if (formula[0] != '=') return 0;
        string f = formula.substr(1); // remove '='
        size_t plusPos = f.find('+');
        string left = f.substr(0, plusPos);
        string right = f.substr(plusPos + 1);

        int val1 = isNumber(left) ? stoi(left) : sheet[parseCell(left).first][parseCell(left).second];
        int val2 = isNumber(right) ? stoi(right) : sheet[parseCell(right).first][parseCell(right).second];

        return val1 + val2;
  
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */