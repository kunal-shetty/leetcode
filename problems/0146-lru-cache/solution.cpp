// 146. LRU Cache
// Difficulty: Medium
// https://leetcode.com/problems/lru-cache/
// Runtime: 264 ms (beats —)
// Memory: 172 MB (beats —)
// Submitted: 2026-06-23

class LRUCache {
public:
    unordered_map<int, int> values;
    unordered_map<int, int> usedTime;
    int timer = 0;
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (values.find(key) == values.end())
            return -1;
        timer++;
        usedTime[key] = timer;
        return values[key];
    }

    void put(int key, int value) {
        timer++;
        int leastTime = INT_MAX;
        int leastKey = -1;
        if(values.find(key) != values.end()){
            values[key] = value;
            usedTime[key] = timer;
            return;
        }
        if (values.size() == capacity) {
            for (auto [k, v] : usedTime) {
                if (v < leastTime) {
                    leastTime = v;
                    leastKey = k;
                }
            }
            values.erase(leastKey);
            usedTime.erase(leastKey);
        }
        values[key] = value;
        usedTime[key] = timer;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
