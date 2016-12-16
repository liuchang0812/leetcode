#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size() == 0) return 0;
        if (heaters.size() == 0) return INT_MAX;  
        cout << houses.size() << ' ' << heaters.size() << endl;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        
        size_t idx_house, idx_heater;
        idx_house = idx_heater = 0;

        for(; idx_house < houses.size(); ++idx_house)
        {
            while (idx_heater + 1 < heaters.size() && abs(houses[idx_house] - heaters[idx_heater+1]) <= abs(houses[idx_house] - heaters[idx_heater]))
            {
                ++ idx_heater;
            }
        
            ans = max(ans, abs(houses[idx_house] - heaters[idx_heater]));
        }
        return ans;
    }
};

int main()
{
vector<int> houses;
vector<int> heaters;
for (int i=0; i<15226; ++i)
	houses.push_back(i),heaters.push_back(i);

Solution sol;
cout << sol.findRadius(houses, heaters) << endl;
}
