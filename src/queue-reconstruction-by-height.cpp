#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    sort(people.begin(), people.end());

    vector<pair<int, int> > ans;
    ans.resize(people.size());
    bool fill[1105];
    memset(fill, 0, sizeof fill);

    for (int i=0; i<people.size(); ++i) {
        cout << "queuing <" << people[i].first << " , " << people[i].second << ">" << endl;
        pair<int, int> item = people[i];
        int k = item.first;
        int n = item.second;
        int p = 0;
        for (int j=0; j<people.size(); ++j) {
            if (p==n) {
                int tmp = j;
                while (fill[tmp]) ++tmp;
                fill[tmp] = true;
                ans[tmp] = people[i];

                cout << "setting <" << people[i].first << " , " << people[i].second << "> to " << tmp << endl;
                break;
            }
            if (!fill[j] || ans[j].first >= k) ++p;
        }
    }

    return ans;
    }
};

int main() {
    vector<pair<int, int> > input;
   input.push_back(make_pair(7,0));
   input.push_back(make_pair(4,4));
   input.push_back(make_pair(7,1));
   input.push_back(make_pair(5,0));
   input.push_back(make_pair(6,1));
   input.push_back(make_pair(5,2));
    Solution sol;
    auto ans = sol.reconstructQueue(input);
    for (auto i:ans)
	    cout << i.first << ' ' << i.second << endl;
    return 0;
}
