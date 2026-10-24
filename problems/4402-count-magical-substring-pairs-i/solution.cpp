// 4402. count magical substring pairs i
// Difficulty: Unknown
// https://leetcode.com/problems/count-magical-substring-pairs-i/
// Runtime: 97 ms (beats 87.5%)
// Memory: 30.9 MB (beats 56.3%)
// Submitted: 2026-10-24

class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        long long res = 0;
        for(int j = 0; j < n-1;j++){
            vector<int> left(27), right(27), seen(27);
            int d = 0;
            for(int i  = j; i >= 0; i--){
                if(!seen[s[i] - 'a']++) d++;
                left[d]++;
            }
            fill(seen.begin(), seen.end(), 0);
            d = 0;
            for(int k = j + 1;k<n;k++){
                if(!seen[s[k] - 'a']++) d++;
                right[d]++;
            }
            for(int i = 1; i <=26;i++){
                res += 1LL * left[i] * right[i];
            }
        }
        return res;
    }
};
