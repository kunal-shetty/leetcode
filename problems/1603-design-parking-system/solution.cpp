// 1603. Design Parking System
// Difficulty: Easy
// https://leetcode.com/problems/design-parking-system/
// Runtime: 8 ms (beats —)
// Memory: 38.8 MB (beats —)
// Submitted: 2026-05-28

class ParkingSystem {
public:
int maxBig, maxMedium, maxSmall, bigCars, mediumCars, smallCars;
    ParkingSystem(int big, int medium, int small) {
        bigCars = 0; maxBig = big;
        mediumCars = 0; maxMedium = medium;
        smallCars = 0; maxSmall = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && bigCars < maxBig) return ++bigCars;
        if(carType == 2 && mediumCars < maxMedium) return ++mediumCars;
        if(carType == 3 && smallCars < maxSmall) return ++smallCars;
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
