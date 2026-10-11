// 4080. Design Bus Seat Booking System
// Difficulty: Medium
// https://leetcode.com/problems/design-bus-seat-booking-system/
// Runtime: 185 ms (beats —)
// Memory: 330.2 MB (beats —)
// Submitted: 2026-10-11

class BusBooking {
public:
     vector<vector<bool>> booked;
        vector<vector<int>> cost;
        int total = 0, c = 0;
    BusBooking(int n) {
       booked.resize(n + 1, vector<bool>(4, false));
        cost.resize(n + 1, vector<int>(4,0));
    }
    
    void toggle(string seat) {
        int j = seat[0] -'A';
        int i = stoi(seat.substr(1));

        if(booked[i][j]){
            total -= cost[i][j];
            booked[i][j] = false;
            cost[i][j] = 0;
            c --;
        }
        else {
            int ct = 1;
            if(j == 0 && booked[i][1]) ct = 3;
            if(j == 3 && booked[i][2]) ct = 3;

            booked[i][j] = true;
            cost[i][j] = ct;
            total += ct;
            c++;
        }
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return c;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
