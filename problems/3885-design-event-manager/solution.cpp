// 3885. Design Event Manager
// Difficulty: Medium
// https://leetcode.com/problems/design-event-manager/
// Runtime: 254 ms (beats —)
// Memory: 311.5 MB (beats —)
// Submitted: 2026-03-29

class EventManager {
public:
    struct Node {
        int priority;
        int id;

        bool operator<(const Node& other) const {
            if (priority != other.priority)
                return priority > other.priority; // higher first
            return id < other.id; // smaller id first
        }
    };

    set<Node> st;
    unordered_map<int, int> mp;

    EventManager(vector<vector<int>>& events) {
        for (int i = 0; i < events.size(); i++) {
            int id = events[i][0];
            int pr = events[i][1];
            mp[id] = pr;
            st.insert({pr, id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int old = mp[eventId];
        st.erase(Node{old, eventId});
        mp[eventId] = newPriority;
        st.insert({newPriority, eventId});
    }
    
    int pollHighest() {
        if (st.empty()) return -1;

        Node top = *st.begin();
        st.erase(st.begin());
        mp.erase(top.id);

        return top.id;
    }
};
