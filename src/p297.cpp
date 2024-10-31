/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    //int vals[5900005];
class Codec {
public:

    // Encodes a tree to a single string.
    string buffer;
    vector<int> nums;
    int cur;

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            buffer +=  "2000,";
            return;
        }
        buffer += to_string(root->val) + ",";
        dfs(root->left);
        dfs(root->right);
    }

    string serialize(TreeNode* root) {
        buffer = "";
        dfs(root);
        return buffer;
    }

    TreeNode* dfs2() {
        if (nums[cur] == 2000) {
            ++cur;
            return nullptr;
        }
        auto* node = new TreeNode(nums[cur]);
        ++cur;

        auto left = dfs2();
        auto right = dfs2();
        node->left = left;
        node->right = right;
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        nums.clear();

        int v = 0;
        int i = 0;
        while (i < data.size()) {
            bool neg = false;
            while (data[i] != ',') {
                if (data[i] == '-') { neg = true; ++i; continue;}
                v = v * 10 + data[i] - '0';
                ++i;
            }
            nums.push_back(neg ? -v : v);
            ++i;
            v = 0;
        }
        cur = 0;
        return dfs2();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
