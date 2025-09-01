class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        
        auto calculateGain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        for (auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double gain = calculateGain(pass, total);
            pq.push({gain, {pass, total}});
        }
        
        while (extraStudents--) {
            auto [currentGain, params] = pq.top();
            int pass = params.first;
            int total = params.second;
            pq.pop();
            
            pass++;
            total++;
            double newGain = calculateGain(pass, total);
            pq.push({newGain, {pass, total}});
        }
        
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto [gain, params] = pq.top();
            int pass = params.first;
            int total = params.second;
            totalRatio += (double)pass / total;
            pq.pop();
        }
        
        return totalRatio / n;
    }
};