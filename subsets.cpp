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
