class ParkingSystem {
public:   
    int nums[3];
    ParkingSystem(int big, int medium, int small) {
        nums[0] = big;
        nums[1] = medium;
        nums[2] = small;
    }
    
    bool addCar(int carType) {
        if((nums[carType-1]--) > 0)
            return true;
        
        return false;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */