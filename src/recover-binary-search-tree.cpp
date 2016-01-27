
class Solution {
  public:
      void dfs(vector<int>& ans, TreeNode* root)
      {
          if (root == NULL)
              return;

          dfs(ans, root->left);
          ans.push_back(root->val);
          dfs(ans, root->right);
      }

      TreeNode* get(TreeNode* root,  int val)
      {
          if (root==NULL) return NULL;
          
          if (root->val == val)
          {
              return root;
          }
          
          TreeNode* ret1 = get(root->left, val);
          if (ret1!=NULL) return ret1;
          TreeNode* ret2 = get(root->right, val);
          if (ret2!=NULL) return ret2;
          
      }

      void recoverTree(TreeNode* root)  {
          vector<int> midScan;
          dfs(midScan, root);
          
          cout << "dfs ok" << endl;
          
          int val1, val2;
          for (size_t i=0; i<midScan.size()-1; ++i)
          {
              if (midScan[i] > midScan[i+1] && (i == 0 || midScan[i] > midScan[i-1]))
              {
                  val1 = midScan[i];
                  break;
              }
          }

          for (size_t i=1; i<midScan.size(); ++i)
              if (midScan[i] < midScan[i-1] && (i == midScan.size()-1 || midScan[i] < midScan[i+1]))
              {
                  val2 = midScan[i];
                  
              }
          TreeNode *n1, *n2;
          n1 = NULL; n2 = NULL;
          
          //cout << val1 << ' ' << val2 << endl;
          
          n1 = get(root, val1);
          n2 = get(root, val2);
          
          //cout << n1->val << endl;
          //cout << n2->val << endl;
          //cout << "get ok" <<endl;
          
          int tmp = n1->val; n1->val = n2->val; n2->val = tmp;

       return;
      }
  };
