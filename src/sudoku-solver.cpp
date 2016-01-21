#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
  public:

      int finded;
   void pnt_matrix(const vector<vector<char>> &board)
      {
          for(size_t i=0; i<board.size(); ++i)
          {
              for (size_t j=0; j<board[0].size(); ++j)
              {
                  cout << board[i][j] << ' ' ;
              }
              cout << endl;
          }
      }
      
      void dfs(vector<vector<char>>& board, int x_, int y_, vector<vector<char>>& ans)
      {
          if (finded) return;
        if(y_ >= board[0].size()) {
              x_ ++;
              y_ = 0;
          }

       if(x_ >= board.size()){
              finded = true;
              pnt_matrix(board);
              for (size_t i=0; i<9; i++)
                for (size_t j=0; j<9; j++)
                {
                    ans[i][j] = board[i][j];
                }
              return;
          }

          char c = board[x_][y_];

          if (c!='.')
          {
              dfs(board, x_, y_+1, ans);
          }

          else
          {
              // try this cell
              map<char, int> cnt;
              // row
            for  (int i=0; i<board[0].size(); ++i) cnt[board[x_][i]] ++;

              // col
            for (int i=0; i<board.size(); ++i) cnt[board[i][y_]] ++;

              // box
              for (int i= x_/3 * 3; i< x_/3 * 3 + 3; ++i)
                  for (int j=y_/3*3; j<y_/3*3 + 3; ++j)
                      cnt[board[i][j]] ++;


              for (char c='1'; c<='9'; ++c)
                  if (cnt[c]==0)
                  {
                   if (finded==false)
                      {
                          board[x_][y_] = c;
                            //cout << "x y c: " << x_ << ' ' << y_ << ' ' <<  c << endl;
                          dfs(board, x_, y_+1, ans);
                          if(finded==false)
                            board[x_][y_] = '.';
                      }
                  }
          }
      }

      void solveSudoku(vector<vector<char>>& board) {
          finded = false;
          vector<vector<char>>& copy(board);
          dfs(copy, 0, 0, board);
      }
  };

int main()
{

}
