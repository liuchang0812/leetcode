/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmp(const Interval& lft, const Interval& rht)
    {
        return lft.start < rht.start;
    }
    
class Solution {
public:
    
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> intervals_copy(intervals);
        intervals_copy.push_back(newInterval);
        sort(intervals_copy.begin(), intervals_copy.end(), cmp);
        
        stack<Interval> ansStack;
        ansStack.push(intervals_copy[0]);
        
        for (size_t i=1; i<intervals_copy.size(); ++i)
        {
            Interval i1, i2;
            i1 = ansStack.top(); ansStack.pop();
            i2 = intervals_copy[i];
            
            if (i2.start <= i1.end)
            {
                ansStack.push(Interval(i1.start, max(i1.end, i2.end)));
            }
            else
            {
                ansStack.push(i1);
                ansStack.push(i2);
            }
        }
        vector<Interval> ans;
        while (!ansStack.empty())
        {
            ans.push_back(ansStack.top());
            ansStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
