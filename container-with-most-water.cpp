#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
       int ans = 0;
       int l, r;
       l = 0;
       r = height.size()-1;
       while( l < r)
       {
           while (l < r && height[l] >= height[r])
           {
               ans = max(ans, (r-l) * height[r]);
               r -- ;
           }
           while (l < r && height[l] <= height[r])
           {
               ans = max(ans, (r-l) * height[l]);
               l++;
           }
       }
       return ans;
    }
};


int main(){
    Solution s;
    vector<int> height;
    height.push_back(1);
    height.push_back(5);
    height.push_back(2);
    height.push_back(3);
    height.push_back(2);
    cout << s.maxArea(height) << endl;
    return 0;
}
