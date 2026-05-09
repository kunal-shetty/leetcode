// 705. Design HashSet
// Difficulty: Easy
// https://leetcode.com/problems/design-hashset/
// Runtime: 35 ms (beats —)
// Memory: 83.2 MB (beats —)
// Submitted: 2026-05-09

class MyHashSet {
public:
bool hashset[1000001];
    MyHashSet() {
       fill(hashset, hashset + 1000001, false);
    }
    
    void add(int key) {
        hashset[key] = true;
    }
    
    void remove(int key) {
        hashset[key] = false;
    }
    
    bool contains(int key) {
        if(hashset[key]) return true;
        return false;;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
