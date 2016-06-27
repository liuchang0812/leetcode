class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        
        int lft = 0;
        int rht = num;
        int mid;
        while (lft < rht)
        {
            mid = lft + (rht - lft) / 2;
            cout << lft << ' ' << mid << ' ' << rht << endl;
            if (num / mid == mid && num % mid == 0) return true;
            else if (num / mid >= mid)
                lft = mid + 1;
            else
                rht = mid;
        }
        return false;
    }
};
