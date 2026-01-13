class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0.0, high = 0.0;
        double totalArea = 0.0;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            high = max(high, y + l);
            totalArea += l * l;
        }

        for (int iter = 0; iter < 80; iter++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &s : squares) {
                double y = s[1], l = s[2];

                if (mid <= y) {
                    continue; 
                } 
                else if (mid >= y + l) {
                    areaBelow += l * l; 
                } 
                else {
                    areaBelow += (mid - y) * l; 
                }
            }

            if (areaBelow * 2.0 < totalArea)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
