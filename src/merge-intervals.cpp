#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <stack>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool mycmp(const Interval& lft, const Interval& rht)
{
    return lft.start < rht.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
       //cout << "start programing" << endl;
       sort(intervals.begin(), intervals.end(), mycmp);
       stack<Interval> s;
       for (size_t i=0; i<intervals.size(); ++i)
       {
           //cout << i << ' ' << intervals[i].start << ' ' << intervals[i].end << endl;
           if (s.empty())
           {
               s.push(intervals[i]);
           }
           else
           {
               Interval t = s.top();
               Interval t2 = intervals[i];

               if (t.end >= t2.start)
               {
                    s.pop();

                    Interval i(t.start, max(t.end, t2.end));
                    s.push(i);
               }
               else
               {
                   s.push(t2);
               }
           }
       }

       vector<Interval> ans;

       while (!s.empty())
       {
           ans.push_back(s.top());
           s.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};


void pnt_intevals(const vector<Interval>& ints)
{
    for (auto i:ints)
    {
        cout << i.start << ' ' << i.end << endl;
    }
}

int main()
{
    vector<Interval> inp;
    // [1,3],[2,6],[8,10],[15,18]
    inp.push_back(Interval(1,3));
    inp.push_back(Interval(2,6));
    inp.push_back(Interval(8,10));
    inp.push_back(Interval(15,18));
    pnt_intevals(Solution().merge(inp));
    return 0;
}
