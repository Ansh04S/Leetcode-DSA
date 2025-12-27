class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
    
    priority_queue<int, vector<int>, greater<int>> available;
    vector<int> count(n, 0);

    for (int i = 0; i < n; i++) {
        available.push(i);
    }

    for (const auto& m : meetings) {
        int originalStart = m[0];
        int duration = m[1] - m[0];
        while (!occupied.empty() && occupied.top().first <= originalStart) {
            available.push(occupied.top().second);
            occupied.pop();
        }
        if (available.empty()) {
            auto [endTime, room] = occupied.top();
            occupied.pop();
            long long actualStart = endTime;
            long long actualEnd = actualStart + duration;
            
            occupied.push({actualEnd, room});
            count[room]++;
        } else {
            int room = available.top();
            available.pop();
            
            long long actualStart = originalStart;
            long long actualEnd = actualStart + duration;
            
            occupied.push({actualEnd, room});
            count[room]++;
        }
    }
    
    int maxRoom = 0;
    int maxCount = count[0];
    
    for (int i = 1; i < n; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxRoom = i;
        }
    }
    
    return maxRoom;
    }
};