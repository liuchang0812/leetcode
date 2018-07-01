class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
	    int haves[3] = {0, 0, 0}; // 5, 10, 20

	    int ans = true;

	    for (int i = 0; i<bills.size(); ++i)
	    {
		    int fee = bills[i];
		    if (fee == 5)
			    ++ haves[0];
		    else if (fee == 10)
		    {
			if (haves[0] > 0)
			{
				--haves[0];
				++haves[1];
			} else
				return false;
		    } else {
			if (haves[1] >= 1 && haves[0] >= 1)
			{
				++haves[2];
				--haves[1];
				--haves[0];
			} else if (haves[0] >= 3) {
				++haves[2];
				haves[0] -= 3;
			}
			else
				return false;
		    }
	    }
        return true;
    }
};
