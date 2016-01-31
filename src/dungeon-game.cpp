class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int lenx = dungeon.size();
        if (lenx == 0) return 0;
        
        int leny = dungeon[0].size();
        
        int f[lenx+1][leny+1];
        
        if (dungeon[lenx-1][leny-1] < 0)
            f[lenx][leny] = 1-dungeon[lenx-1][leny-1];
        else
            f[lenx][leny] = 1;
        cout << lenx << ' ' << leny << ' ' << f[lenx][leny] << endl;
        for (int x = lenx; x>=1; x--)
            for (int y=leny; y>=1; y--)
            {
                if( x==lenx && y==leny) continue;
                int ret = INT_MAX;
                
                if (x + 1 <= lenx)
                    ret = min(ret, f[x+1][y]);
                
                if (y + 1 <= leny)
                    ret = min(ret, f[x][y+1]);
                
                if (dungeon[x-1][y-1] <= 0)
                    f[x][y] = ret - dungeon[x-1][y-1];
                else
                {
                    int tmp = ret - dungeon[x-1][y-1];
                    if (tmp < 0)
                        f[x][y] = 1;
                    else if (tmp == 0)
                        f[x][y] = 1;
                    else
                        f[x][y] = tmp;
                }
                //cout << x << ' ' << y <<' '<< f[x][y] << endl;
                
            }
        return f[1][1];
    }
};
