class TaskManager {
    private:
    struct TaskInfo {
        int userId;
        int priority;
        bool valid;
    };
    
    unordered_map<int, TaskInfo> taskMap;
    
    struct HeapEntry {
        int priority;
        int taskId;
        int userId;
        HeapEntry(int p, int t, int u) : priority(p), taskId(t), userId(u) {}
    };
    
    struct Compare {
        bool operator()(const HeapEntry& a, const HeapEntry& b) {
            if (a.priority == b.priority) {
                return a.taskId < b.taskId;
            }
            return a.priority < b.priority;
        }
    };
    
    priority_queue<HeapEntry, vector<HeapEntry>, Compare> heap;
public:
    TaskManager(vector<vector<int>>& tasks) {
         for (auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority, true};
        heap.push(HeapEntry(priority, taskId, userId));
    }
    
    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) != taskMap.end()) {
            taskMap[taskId].valid = false;
        }
        taskMap[taskId] = {taskMap[taskId].userId, newPriority, true};
        heap.push(HeapEntry(newPriority, taskId, taskMap[taskId].userId));
    }
    
    void rmv(int taskId) {
        if (taskMap.find(taskId) != taskMap.end()) {
            taskMap[taskId].valid = false;
            taskMap.erase(taskId);
        }

    }
    
    int execTop() {
        while (!heap.empty()) {
        HeapEntry top = heap.top();
        heap.pop();
        if (taskMap.find(top.taskId) == taskMap.end()) {
            continue;
        }
        TaskInfo& info = taskMap[top.taskId];
        if (!info.valid || info.priority != top.priority) {
            continue;
        }
        int resultUserId = info.userId;  
        taskMap.erase(top.taskId);
        return resultUserId;  
    }
    return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */