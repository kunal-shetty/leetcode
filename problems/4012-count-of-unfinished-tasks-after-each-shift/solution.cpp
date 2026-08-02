// 4012. Count of Unfinished Tasks After Each Shift
// Difficulty: Medium
// https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/
// Runtime: 16 ms (beats —)
// Memory: 162.6 MB (beats —)
// Submitted: 2026-08-02

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + tasks[i];
        }
        vector<int> ans;
        int idx = 0;
        long long done = 0;

        for (long long t : shifts) {
            if (idx == n) {
                idx = 0;
                done = 0;
            }

            if (done > 0) {
                long long need = tasks[idx] - done;
                if (t < need) {
                    done += t;
                    ans.push_back(n - idx);
                    continue;
                }
                t -= need;
                idx++;
                done = 0;

                if (idx == n) {
                    ans.push_back(0);
                    idx = 0;
                    done = 0;
                    continue;
                }
            }

            long long target = pref[idx] + t;
            int nxt = upper_bound(pref.begin(), pref.end(), target) -
                      pref.begin() - 1;

            t -= pref[nxt] - pref[idx];
            idx = nxt;

            if (idx == n) {
                ans.push_back(0);
                idx = 0;
                done = 0;
                continue;
            }

            if (t == tasks[idx]) {
                idx++;
                if (idx == n) {
                    ans.push_back(0);
                    idx = 0;
                    done = 0;
                } else {
                    done = 0;
                    ans.push_back(n - idx);
                }
            } else {
                done = t;
                ans.push_back(n - idx);
            }
        }
        return ans;
    }
};
