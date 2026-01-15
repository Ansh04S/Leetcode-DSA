class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
          std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());
        
        int maxH = 1; 
        int currentH = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i-1] + 1) {
                currentH++;
            } else {
                currentH = 1;
            }
            maxH = std::max(maxH, currentH);
        }
        
        int maxV = 1; 
        int currentV = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i-1] + 1) {
                currentV++;
            } else {
                currentV = 1;
            }
            maxV = std::max(maxV, currentV);
        }
               
        int maxSide = std::min(maxH + 1, maxV + 1);
        return maxSide * maxSide;
    }
};