class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
         int n = bottomLeft.size();
        long long maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
               
                int xLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
                int xRight = min(topRight[i][0], topRight[j][0]);
                
                int yBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int yTop = min(topRight[i][1], topRight[j][1]);
                
               
                if (xLeft < xRight && yBottom < yTop) {
                    int width = xRight - xLeft;
                    int height = yTop - yBottom;
                    
                    int side = min(width, height);
                    long long area = 1LL * side * side;
                    
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};