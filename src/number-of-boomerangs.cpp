#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int booms = 0;
        for (auto& p : points)
        {
            unordered_map<int, int> mp(n);            
            for (auto& q : points)
            {
                int x = p.first - q.first;
                int y = p.second - q.second;
                int d = x*x + y*y;
                booms += 2*mp[d]++;
            }
        }
        return booms;
    }
};
