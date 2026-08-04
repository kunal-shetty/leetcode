// 134. Gas Station
// Difficulty: Medium
// https://leetcode.com/problems/gas-station/
// Runtime: 0 ms (beats —)
// Memory: 112.3 MB (beats —)
// Submitted: 2026-08-04

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentTank += gas[i] - cost[i];

            if (currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        return totalGas >= totalCost ? startingStation : -1;
    }
};
