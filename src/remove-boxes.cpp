class Solution {
public:
    struct Seg {
        int color;
        int len;
    };

    vector<Seg> segs;

   int cache[105][105][105];
    int dfs(const vector<Seg>& segs, int i, int j, int qlen) {
       // cout << i << ' ' << j << ' ' << qlen << endl;
        if (cache[i][j][qlen] != 0) {
            return cache[i][j][qlen];
        }

        int result = (segs[j].len + qlen)*(segs[j].len + qlen);
        if (i ==j ) return result;
        result += dfs(segs, i, j-1, 0);
 
           for (int k=i; k<j; ++k) {
               if (segs[k].color != segs[j].color) continue; 
               int r = dfs(segs, k+1, j-1, 0);
               r += dfs(segs, i, k, segs[j].len + qlen);
               result = max(result, r);
           } 
        
        cache[i][j][qlen] = result;
        return result;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(cache, 0, sizeof cache);
        int c,l;
        c = boxes[0];
        l = 1;
        for (int i=1; i<boxes.size(); ++i) {
            if (boxes[i] == c) ++l;
            else {
                segs.push_back({
                    c, l
                });
                c = boxes[i];
                l = 1;
            }
        }
        segs.push_back({
                    c, l
        });

        return dfs(segs, 0, segs.size()-1, 0);
    }
};
