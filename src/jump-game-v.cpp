class Solution {
public:
    int f[1000];
    int dfs(vector<int>& arr, int p, int d) {
        //cout <<"try " << p << endl;
        if (p<0 || p>=arr.size()) return 0;
        if (f[p] != 0) return f[p];
        else {
           
            int tmp = 0;
            for (int i = p-d; i<= p+d; ++i) {
                if (i>=0 && i<arr.size() && i!= p && arr[i] < arr[p]) {
                    bool b = true;
                    for (int k=min(p,i)+1; k<max(p,i); ++k) 
                        if (arr[k]>=arr[p]) { b=false;break; }
                    if (b) 
                        tmp = max(tmp, dfs(arr, i, d));
                }
            }
            f[p] = tmp+1;
             cout << " dfs " << p << ' ' << f[p] << endl;
            return f[p];
        }
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(f, 0, sizeof f);
        for(int i=0;i<arr.size();++i) {
            dfs(arr, i, d);
        }
        int ans = 0;
        for (int i=0;i<arr.size();++i) ans = max(ans, f[i]);
        return ans;
    }
};
