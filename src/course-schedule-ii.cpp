class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > E(numCourses);
        vector<int> in(numCourses);

        for (auto i: prerequisites)
        {
            E[i.second].push_back(i.first);
            in[i.first] += 1;
        }
        vector<int> ans;
        int round = 0;
        do
        {
            if (round == numCourses) return ans;
            size_t i;
            for ( i = 0; i < numCourses; ++i)
            {
                if (in[i] == 0) break;
            }

            if (i == numCourses)
                return vector<int>();

            for (auto j:E[i])
                in[j] --;
            round ++;
            in[i] = -1;
            ans.push_back(i);
        } while (true);
        if (round == numCourses) return ans;
    }
};
