// 3454. Separate Squares II
// Difficulty: Hard
// https://leetcode.com/problems/separate-squares-ii/
// Runtime: 669 ms (beats —)
// Memory: 134 MB (beats —)
// Submitted: 2026-01-14

class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type; // +1 add, -1 remove
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });

        vector<double> xs;
        for (auto &e : events) {
            xs.push_back(e.x1);
            xs.push_back(e.x2);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int n = xs.size();
        vector<int> cnt(4 * n);
        vector<double> len(4 * n);

        function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int ql, int qr) {
            if (ql >= r || qr <= l) return;
            if (ql <= l && r <= qr) cnt[node]++;
            else {
                int mid = (l + r) / 2;
                update(node*2, l, mid, ql, qr);
                update(node*2+1, mid, r, ql, qr);
            }
            if (cnt[node] > 0) len[node] = xs[r] - xs[l];
            else if (l + 1 == r) len[node] = 0;
            else len[node] = len[node*2] + len[node*2+1];
        };

        function<void(int,int,int,int,int)> remove = [&](int node, int l, int r, int ql, int qr) {
            if (ql >= r || qr <= l) return;
            if (ql <= l && r <= qr) cnt[node]--;
            else {
                int mid = (l + r) / 2;
                remove(node*2, l, mid, ql, qr);
                remove(node*2+1, mid, r, ql, qr);
            }
            if (cnt[node] > 0) len[node] = xs[r] - xs[l];
            else if (l + 1 == r) len[node] = 0;
            else len[node] = len[node*2] + len[node*2+1];
        };

        double totalArea = 0;
        double prevY = events[0].y;

        for (auto &e : events) {
            totalArea += len[1] * (e.y - prevY);

            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();

            if (e.type == 1) update(1, 0, n - 1, l, r);
            else remove(1, 0, n - 1, l, r);

            prevY = e.y;
        }

        double half = totalArea / 2.0;
        fill(cnt.begin(), cnt.end(), 0);
        fill(len.begin(), len.end(), 0);

        double areaSoFar = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            double dy = e.y - prevY;
            double sliceArea = len[1] * dy;

            if (areaSoFar + sliceArea >= half) {
                return prevY + (half - areaSoFar) / len[1];
            }

            areaSoFar += sliceArea;

            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();

            if (e.type == 1) update(1, 0, n - 1, l, r);
            else remove(1, 0, n - 1, l, r);

            prevY = e.y;
        }

        return prevY;
    }
};
