class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        map<pair<int, int>, bool> v;
        
        int posx, posy; posx = posy = 0;
        
        int n = matrix.size() * matrix[0].size();
        int d = 0;
        while (n --)
        {
            ans.push_back(matrix[posx][posy]);
            v[make_pair(posx, posy)] = true;
            int nx, ny;
            
            nx = posx + dx[d]; ny = posy + dy[d];
            
            if (n)
            {
            while(nx < 0 || nx == matrix.size() ||
                ny < 0 || ny == matrix[0].size() ||
                v[make_pair(nx, ny)])
            {
                d ++;
                d %=4;
                nx = posx + dx[d]; ny = posy + dy[d];
            }
            
            posx = nx;
            posy = ny;
            }
        }
        return ans;
    }
};
