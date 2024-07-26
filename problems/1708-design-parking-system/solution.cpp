class ParkingSystem {
private:
    int big;
    int med;
    int sma;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->med = medium;
        this->sma = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (big == 0) {
                return false;
            }
            big--;
            return true;
        }
        if (carType == 2) {
            if (med == 0) {
                return false;
            }
            med--;
            return true;
        }
        if (sma == 0) {
            return false;
        }
        sma--;
        return true;

    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */