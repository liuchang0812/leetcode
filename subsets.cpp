/*
利用位运算实现，妈蛋竟然还要顺序。。
*/

class Solution {
public:
    
    vector<vector<int> > subsets(vector<int> &S) {
        int count = S.size();
        vector<vector<int> > anss;
        for (int i = 0;i < (1 << count ); i ++ )
        {
            vector<int> ans;
            int mask = 1;
            for(int j = 1;j <= count; j ++)
            {
                if ( mask & i)
                {
                    ans.push_back(S[j-1]);
                }
                mask = mask << 1;
            }
            anss.push_back(ans);
        }
        return anss;
    }
};

/*
正确版
*/

class Solution {
public:
    vector<int> selected;
    vector<vector<int> >ans;
    void dfs(int index,vector<int>& nums, int used, int target)
    {
        if( used == target)
        {
            ans.push_back(selected);
            return;
        }
        if(index == nums.size())
            return;
        // yao
        selected.push_back(nums[index]);
        dfs(index+1,nums,used+1,target);
        selected.pop_back();
        // bu yao
        dfs(index+1,nums,used,target);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        for(int i = 0;i <= S.size();i ++)
        {
            dfs(0, S, 0, i);
        }
        return ans;
    }
};
