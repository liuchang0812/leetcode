#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:

    void dfs(int current_dep, int current_sum, vector<int>& current_numbers, const vector<int>& candidates, int target, set<vector<int> > &ans)
    {
        cerr << current_dep << ' ' << current_sum << endl;        
        if (current_sum == target){
            ans.insert(current_numbers);
            cerr << "Got it" << endl;
        }
        if (current_dep == candidates.size()) return;
        if (current_sum > target) return;

        // skip this number
        dfs(current_dep+1, current_sum, current_numbers, candidates, target, ans);

        // pick this number
        current_numbers.push_back(candidates[current_dep]);
        dfs(current_dep+1, current_sum+candidates[current_dep], current_numbers, candidates, target, ans);
        current_numbers.pop_back(); 
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current_numbers;
        vector<vector<int> >ans;
        set<vector<int> >sans;
        dfs(0, 0,  current_numbers, candidates, target, sans);
        for (auto i:sans)
            ans.push_back(i);
        return ans;
    }
};


int main()
{

    vector<int> inp;
    //inp.push_back(10);
    inp.push_back(1);
    /*
    inp.push_back(2);
    inp.push_back(7);
    inp.push_back(6);
    inp.push_back(1);
    inp.push_back(5);
    */

    vector<vector<int> > ans;
    ans = Solution().combinationSum2(inp, 1);
    cout << ans.size() << endl;
    return 0;
}
