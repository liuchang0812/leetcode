#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

class Solution {
public:
    map<int, vector<int> >num2id;
    int f[20005][15];
    void buildST(const  vector<int>& heights)
    {
        for (int i=0; i<heights.size(); ++i)
            f[i][0] = heights[i];

        for (int i=1; (1<<i) <= heights.size(); i++)
            for (int j=0; j+(1<<(i-1))<heights.size(); j++)
            {
                f[j][i] = min(f[j][i-1], f[j+(1<<(i-1))][i-1]);
            }
    }
    
    int queueMin(int left, int right)
    {
        int diff = right-left;

        int log2 = int(log(diff)/log(2));
        int t = right-pow(2, log2);
        return min(f[left][log2], f[t][log2]);
    }

    int dfs(const vector<int>& heights, int left, int right)
    {
        // range is [left, right)
        if (right <= left)
            return 0;
        
        if (right - left == 1)
        {
            return heights[left];
        }
        else
        {
            int minn;
            minn = queueMin(left, right);
            
            vector<int> minids;
            int ans = minn * (right - left);
            vector<int> ids = num2id[minn];
            for (size_t i=0; i<ids.size()-1; ++i)
                if (left <= ids[i]+1) 
                    ans = max(ans, dfs(heights, ids[i]+1, min(ids[i+1], right)));
            ans = max(ans, dfs(heights, ids.back()+1, right));
            return ans;
        }

    }


    int largestRectangleArea(vector<int>& heights) {
        buildST(heights);
        for (auto i:heights)
            num2id[i] = vector<int>();
        for (size_t i=0; i<heights.size(); ++i)
            num2id[heights[i]].push_back(i);
        return dfs(heights, 0, heights.size());
    }
};


int main()
{
    vector<int> inp;
    for (int i=0; i<20000; i++)
        inp.push_back(i);
    cout << Solution().largestRectangleArea(inp) << endl;
    return 0;
}
