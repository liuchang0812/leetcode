class Solution {
public:
    int _inner(int& num) {
        int sum = 0, v = num;
        while (v)
        {
            sum += v % 10;
            v /= 10;
        }
        num = sum;
        return sum;
    }
    int addDigits(int num) {
        while (_inner(num) > 9)
        {
            //do it forever;
        }
        return num;
    }
};
