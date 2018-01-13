class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> ans;
        for (auto i:nums) {
            bool next = false;
            for (auto j:ans) 
                if (i==j) next = true;
            if (next) continue;
            //cout << "debug"<<endl;
            bool pushed = false;
            for (auto p=ans.begin(); p!=ans.end(); ++p)
            {
                
                if (i > *p)
                {
                    ans.insert(p, i);
                    pushed = true;
                    break;
                }
            }
            if (!pushed) ans.push_back(i);
            if (ans.size() > 3) ans.pop_back();
            //cout << i <<' ' ;for (int tmp:ans) cout << tmp << ' ' ; cout << endl;
        }
        if (ans.size() == 3) return ans[2];
        else return ans[0];
      } 
};
