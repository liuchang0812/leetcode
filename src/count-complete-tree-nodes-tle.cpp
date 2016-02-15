#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <ctime>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool try_exist(long long mid, TreeNode* root)
    {
        stack<int> s;
        while (mid!=1)
        {
            s.push(mid%2);
            mid /= 2;
        }
        while (!s.empty())
        {
            if (root == NULL)
                return false;

            if (s.top())
                root = root->right;
            else
                root = root->left;
            s.pop();
        }
        return root!=NULL;
    }

    int countNodes(TreeNode* root) {
        std::clock_t    start;
        start = std::clock();
        if (root == NULL) return 0;
        int left = 1;
        int right = INT_MAX;
        int mid;
        // [left, right)
        while (right > left + 1)
        {
            mid = left + ((right - left)>>1);

            if (try_exist(mid, root))
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        return left;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* tmp = new TreeNode(2);
    root->left = tmp;

    Solution().countNodes(root);
    return 0;
}

