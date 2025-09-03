class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
         int n = points.size();
        // Sort by x ascending, and for same x by y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    bool valid = true;
                    for (int k = i+1; k < j; k++) {
                        if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] &&
                            points[k][1] >= points[j][1] && points[k][1] <= points[i][1]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};