/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        buff[0] = big;
        buff[1] = medium;
        buff[2] = small;
    }
    
    bool addCar(int carType) {
        if (buff[carType-1] > 0) {
            buff[carType-1] --;
            return true;
        }
        return false;
    }
private:
    int buff[3];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

