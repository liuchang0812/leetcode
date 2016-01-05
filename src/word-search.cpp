#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(int _x, int _y, int _d, vector<vector<bool> >& visited, const vector<vector<char> >& board, const string& word)
    {
        cerr << _x << ' ' << _y << ' ' << _d << ' ' << word[_d] <<  endl;
        if (_d == word.size()) return true;

        if (_x < 0 || _x >= board.size()) return false;
        if (_y < 0 || _y >= board[0].size()) return false;
        
        if (board[_x][_y] != word[_d]) return false;
        if (visited[_x][_y]) return false;
      
        visited[_x][_y] = true;

        static int dx[4] = {0, 0, -1, 1};
        static int dy[4] = {-1, 1, 0, 0};
        
        bool ret = false;
        for (int i=0; i < 4; ++i)
        {
            if(dfs(_x + dx[i], _y + dy[i], _d+1, visited, board, word))
            {
                ret = true;
                break;
            }
        }
        visited[_x][_y] = false;
        return ret;
    }

    bool exist(vector<vector<char> >& board, string word) {
        // assert NULL
        if (board.size() == 0) return false;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size()));
        for (size_t i=0; i<board.size(); ++i)
            for (size_t j=0; j<board[0].size(); ++j)
            {
                bool ret = dfs(i, j, 0, visited, board, word);
                if (ret) return true;
            }
        return false;
    }
};

int main()
{

    vector<vector<char> > board;
    string word;
    /*
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    */
    vector<char> tmp;
    tmp.push_back('a'); tmp.push_back('b');
    //tmp.push_back('a');  tmp.push_back('b'); tmp.push_back('c'); tmp.push_back('e');
    board.push_back(tmp); tmp.clear();
    //tmp.push_back('s'); tmp.push_back('f'); tmp.push_back('c'); tmp.push_back('s');
    //board.push_back(tmp); tmp.clear();
    //tmp.push_back('a'); tmp.push_back('d'); tmp.push_back('e'); tmp.push_back('e');
    //board.push_back(tmp); tmp.clear();

   cout << "Result: " <<  Solution().exist(board, "ba") << endl;
    return 0;
}
