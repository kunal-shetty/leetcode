// 3629. Minimum Jumps to Reach End via Prime Teleportation
// Difficulty: Medium
// https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/
// Runtime: 1105 ms (beats —)
// Memory: 309.5 MB (beats —)
// Submitted: 2026-05-08

class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> getPrimeFactors(int num) {
        vector<int> primeFactors;
        for (int factor = 2; factor * factor <= num; factor++) {
            if (num % factor == 0) {
                primeFactors.push_back(factor);
                while (num % factor == 0) {
                    num /= factor;
                }
            }
        }
        if (num > 1) {
            primeFactors.push_back(num);
        }
        return primeFactors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> primeToIndices;

        for (int index = 0; index < n; index++) {
            vector<int> primeFactors = getPrimeFactors(nums[index]);
            for (int prime : primeFactors) {
                primeToIndices[prime].push_back(index);
            }
        }

        queue<int> bfsQueue;
        vector<bool> visited(n, false);

        bfsQueue.push(0);
        visited[0] = true;

        int jumps = 0;

        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();
            while (levelSize--) {
                int currentIndex = bfsQueue.front();
                bfsQueue.pop();

                if (currentIndex == n - 1) {
                    return jumps;
                }
                if (currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {
                    visited[currentIndex - 1] = true;
                    bfsQueue.push(currentIndex - 1);
                }
                if (currentIndex + 1 < n && !visited[currentIndex + 1]) {
                    visited[currentIndex + 1] = true;
                    bfsQueue.push(currentIndex + 1);
                }

                int currentValue = nums[currentIndex];
                if (isPrime(currentValue)) {

                    for (int nextIndex : primeToIndices[currentValue]) {
                        if (!visited[nextIndex]) {
                            visited[nextIndex] = true;
                            bfsQueue.push(nextIndex);
                        }
                    }
                    primeToIndices[currentValue].clear();
                }
            }
            jumps++;
        }
        return -1;
    }
};
