class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        OneAns.resize(k);
        dfs(0, 0,n , k);
        return ans;
    }
private:
    vector<int> OneAns;
    vector< vector<int> > ans;
    void dfs(int index, int pre, int from, int target) {
        if (index == target) ans.push_back(OneAns);
        else if (pre == from) return;
        else {
            for (int i = pre+1; i<= from; i++)
            {
                OneAns[index] = i;
                dfs(index + 1, i, from, target);
            }
        }
    }
};
