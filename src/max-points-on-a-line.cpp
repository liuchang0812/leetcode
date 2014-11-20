/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include <algorithm>
using namespace std;


class Solution {
public:
    bool cmp(Point x, Point y)
    {
        return x.x > y.x || (x.x == y.x && x.y > y.y);
    }
    
    bool OneLine(Point p1, Point p2, Point p3)
    {
        return (p2.y - p1.y) * (p3.x - p1.x) == (p3.y - p1.y)*(p2.x-p1.x);
    }

    int maxPoints(vector<Point> &points) {
        if (points.size() <= 2) return points.size();
        
        int cnt = points.size();
        for (int i = 0;i < cnt; i++)
            for (int j=0; j<cnt; j++)
            {
                if (cmp(points[i], points[j]))
                    swap(points[i], points[j]);
            }
        vector<int> flags;flags.push_back(1);
        for (int i=1; i<cnt; ++i)
            if (points[i].x == points[i-1].x && points[i].y==points[i-1].y)
                flags.push_back(0);
            else
                flags.push_back(1);
        vector<Point> _points;
        for(int i = 0;i < cnt; ++i)
        {
            if (flags[i])
                _points.push_back(points[i]);
        }
        cnt = _points.size();
        int ans = 0;
        for (int i = 0;i < cnt;i ++)
            for (int j = i + 1;j < cnt;j ++)
            {
                
                int cur = 2;
                for (int k=0; k<cnt && k!=i && k!=j; ++k)
                {
                    if (OneLine(_points[i], _points[j], _points[k]))
                        cur ++ ;
                }
                ans = max(ans, cur);
            }
        return ans;
    }
};
