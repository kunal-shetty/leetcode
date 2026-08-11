// 380. Insert Delete GetRandom O(1)
// Difficulty: Medium
// https://leetcode.com/problems/insert-delete-getrandom-o1/
// Runtime: 31 ms (beats —)
// Memory: 113.4 MB (beats —)
// Submitted: 2026-08-11

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> idx;

    RandomizedSet() {}

    bool insert(int val) {
        if (idx.count(val)) return false;

        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;

        int i = idx[val];
        int last = nums.back();

        nums[i] = last;
        idx[last] = i;

        nums.pop_back();
        idx.erase(val);

        return true;
    }

    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
};
