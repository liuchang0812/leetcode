class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > E(numCourses);
        vector<int> in(numCourses);
        
        for (auto i: prerequisites)
        {
            E[i.first].push_back(i.second);
            in[i.second] += 1;
        }
        
        int round = 0;
        do
        {
            if (round == numCourses) return true;
            size_t i;
            for ( i = 0; i < numCourses; ++i)
            {
                if (in[i] == 0) break;
            }
            
            if (i == numCourses)
                return false;
            
            for (auto j:E[i])
                in[j] --;
            round ++;
            in[i] = -1;
        } while (true);
        return true;
    }
};
