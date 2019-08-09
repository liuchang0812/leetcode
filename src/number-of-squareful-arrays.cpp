class Solution {
public:
    map<int, int> cnt;
    vector<int> nums;
    map<int64_t, bool> sq;
    map<int, vector<int>> sqs;

    bool isSqual(int pre, int n) {
        if (pre == -1) return true;
        return sq[pre+n];
    }

    int dfs(int pos, int pre, int tt) {
        //cout << "pos pre: " << pos << ' ' << pre << endl;
        if (pos == tt)
            return 1;
        
        int ans = 0;
  
            for (int i=0; i<sqs[pre].size(); ++i)
                if (cnt[sqs[pre][i]] > 0 && isSqual(pre, sqs[pre][i])) {
                    -- cnt[sqs[pre][i]];
                    ans += dfs(pos+1, sqs[pre][i], tt);
                    ++ cnt[sqs[pre][i]];
                }
        return ans;
    }
    int numSquarefulPerms(vector<int>& A) {
        for (int i=0; i<35000; ++i)
            sq[(int64_t)i*i] = true;

        for (auto i:A)
            ++cnt[i];
    for (auto i: cnt) {
        nums.push_back(i.first);
    }
    
    for (auto i:nums) {
        sqs[-1].push_back(i);
        for (auto j:nums) {
            if (isSqual(i, j)) {
                sqs[i].push_back(j);
            
            }
        }
    }

    return dfs(0, -1, A.size()); 
    }
};
