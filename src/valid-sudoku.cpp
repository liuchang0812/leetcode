#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool validSudoku(int _x1, int _y1, int _x2, int _y2, const vector<vector<char>>& board)
    {
        map<char, int> cnt;
        for (int x=_x1; x<=_x2; x++)
            for (int y=_y1; y<=_y2; y++)
                cnt[board[x][y]]++;

        for (char i='1'; i<='9'; i++)
            if (cnt[i] > 1) return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int ret = true;

        // row
        for (int i = 0; i < board.size(); i++)
        {
            if (validSudoku(i,0, i, board[0].size()-1, board) == false) return false;
        }


        // colume
        for (int i=0; i < board[0].size(); i++)
        {
            if (validSudoku(0, i, board.size()-1, i, board) == false) return false;
        }

        // 3*3
        for (int i=0; i < board.size(); i+=3)
            for (int j=0; j<board[0].size(); j+=3)
            {
                if (validSudoku(i, j, i+2, j+2, board) == false) return false;
            }
        return true;        
    }
};
