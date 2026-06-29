// 155. Min Stack
// Difficulty: Medium
// https://leetcode.com/problems/min-stack/
// Runtime: 71 ms (beats —)
// Memory: 152.5 MB (beats —)
// Submitted: 2026-06-29

class MinStack {
public:
    vector<pair<int, int>> stack;

    MinStack() {
    }

    void push(int val) {
        if (stack.empty())
            stack.push_back({val, val});
        else
            stack.push_back({val, min(val, stack.back().second)});
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        return stack.back().second;
    }
};
