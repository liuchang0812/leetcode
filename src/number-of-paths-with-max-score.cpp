class Solution {
public:
    int M[100][100];
    int V[100][100];
    bool visited[100][100] = {false, };
    
    vector<int> pathsWithMaxScore(vector<string>& board, int x=0, int y=0) {
        vector<int> ans = {0, 0};
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size() ||
            board[x][y] == 'X') return ans;
        
        if (x == board.size()-1 && y == board[0].size()-1) return vector<int>{0, 1};
        if (visited[x][y] == true) return vector<int>{M[x][y], V[x][y]};
        vector<vector<int>> refs;
        refs.push_back(pathsWithMaxScore(board, x+1, y));
        refs.push_back(pathsWithMaxScore(board, x, y+1));
        refs.push_back(pathsWithMaxScore(board, x+1, y+1));
        
        long long _m = max(refs[0][0], max(refs[1][0], refs[2][0]));
        long long _v = 0;
        for (int i=0;i<3;++i) if (refs[i][0] == _m) _v = (_v + refs[i][1])%1000000007;
        //cout << x << ' ' << y << ' ' << _m << ' ' << _v << endl;
        long long  _m2 = _m;
        if (board[x][y] != 'E' && _v != 0) _m2 += int(board[x][y]-'0');
        visited[x][y] = true;
        M[x][y] = _m2;
        V[x][y] = _v % 1000000007;
        return vector<int>{_m2, _v};
    }
};
