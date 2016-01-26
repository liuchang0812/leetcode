#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> get(int a, int b) {
        vector<TreeNode*> ans;
        if (a>b) {
            ans.push_back(NULL);
        } else {
            for (int i=a; i<=b; i++)
                for (auto l : get(a, i-1)) 
                    for (auto r : get(i+1, b))
                    {
                        ans.push_back(new TreeNode(i));
                        ans.back()->left=l, ans.back()->right=r;
                    }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>();
        return get(1, n);
    }
};

int main()
{
    int n;
    while (cin  >> n)
    {
        cout << Solution().generateTrees(n).size() << endl;
    }
}
