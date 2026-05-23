// 3829. Design Ride Sharing System
// Difficulty: Medium
// https://leetcode.com/problems/design-ride-sharing-system/
// Runtime: 52 ms (beats —)
// Memory: 145 MB (beats —)
// Submitted: 2026-05-23

class RideSharingSystem {
public:
    queue<int> rider, driver;
    map<int,int> cancel;
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        if (cancel.count(riderId)) cancel.erase(riderId);
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (rider.size() and cancel.count(rider.front())) {
            rider.pop();
        }
        if (rider.size() and driver.size()) {
            auto ans = {driver.front(), rider.front()};
            rider.pop();
            driver.pop();
            return ans;
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        cancel[riderId] = 1;
    }
};
