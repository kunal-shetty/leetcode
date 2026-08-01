// 4008. Minimum Initial Strength to Defeat All Monsters
// Difficulty: Medium
// https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/
// Runtime: 127 ms (beats —)
// Memory: 267.6 MB (beats —)
// Submitted: 2026-08-01

class Solution {
public:
    bool can(long long start, vector<int>& monsters, vector<long long>& bonus){
        long long s = start;
        for(int i = 0; i < (int)monsters.size(); i++){
            if(s + bonus[i] < monsters[i]) return false;
            s = max(0LL,  s - monsters[i]);
        }
        return true;
    }
    
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n + 1, 0 );
        for(auto b : boosts){
            diff[b[0]] += b[2];
            diff[b[1] + 1] -= b[2];
        }

        vector<long long> bonus(n);
        long long c = 0;
        for(int i = 0; i < n; i++){
            c += diff[i];
            bonus[i] = c;
            
        }
        long long lo = 0, hi = accumulate(monsters.begin(), monsters.end(), 0LL);

        while(lo < hi){
            long long mid  = lo + (hi - lo) / 2;
            can(mid, monsters, bonus) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
};
