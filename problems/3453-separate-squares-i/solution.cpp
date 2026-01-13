// 3453. Separate Squares I
// Difficulty: Medium
// https://leetcode.com/problems/separate-squares-i/
// Runtime: 92 ms (beats —)
// Memory: 198.7 MB (beats —)
// Submitted: 2026-01-13

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Calculate total area and y-range
        for (int i = 0; i < squares.size(); i++) {
            double y = squares[i][1];
            double l = squares[i][2];

            totalArea += l * l;
            if (y < low) low = y;
            if (y + l > high) high = y + l;
        }

        double target = totalArea / 2.0;

        // Binary search
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            double area = 0.0;

            // Compute area below y = mid
            for (int i = 0; i < squares.size(); i++) {
                double y = squares[i][1];
                double l = squares[i][2];

                if (mid <= y) {
                    continue;
                } 
                else if (mid >= y + l) {
                    area += l * l;
                } 
                else {
                    area += l * (mid - y);
                }
            }

            if (area < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
