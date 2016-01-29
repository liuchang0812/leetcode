#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Solution {
  public:
      void solve(vector<vector<char>>& board) {
          if (board.size() == 0) return;
          map<pair<int, int>, bool> visited;
          queue<pair<int, int> > Q;

          for (size_t i=0; i<board[0].size(); ++i)
          {
              if (board[0][i] == 'O')
              {
                  Q.push(make_pair(0, i));
                  visited[make_pair(0, i)] = true;

              }
              if (board[board.size()-1][i] == 'O')
              {
                  Q.push(make_pair(board.size()-1, i));
                  visited[make_pair(board.size()-1, i)] = true;
              }
          }

          for (size_t i=0; i<board.size(); ++i)
          {
              if (board[i][0] == 'O')
              {
                  Q.push(make_pair(i, 0));
                  visited[make_pair(i, 0)] = true;
              }
           if (board[i][board[0].size()-1] == 'O')
              {
                  Q.push(make_pair(i, board[0].size()-1));
                  visited[make_pair(i, board[0].size()-1)] = true;
              }
          }
          
          while (!Q.empty())
          {
              pair<int, int> cur_pos = Q.front(); Q.pop();

              if (board[cur_pos.first][cur_pos.second] !='O')
                  continue;
              board[cur_pos.first][cur_pos.second] ='#';

              static int dx[] = {-1, 1, 0, 0};
              static int dy[] = {0, 0, -1, 1};
              for (int i=0; i<4; ++i)
              {
                  int px = cur_pos.first + dx[i];
                  int py = cur_pos.second + dy[i];
                if (px < 0 || px >= board.size() ||
                    py < 0 || py >= board[0].size() ||
                      visited[make_pair(px, py)])
                      continue;
                  Q.push(make_pair(px, py));
                  visited[make_pair(px, py)] = true;
              }

          }
          
          for (size_t i=0; i<board.size(); ++i)
              for (size_t j=0; j<board[0].size(); ++j)
              {
                  if (board[i][j] == 'O')
                      board[i][j] = 'X';
                  if (board[i][j] == '#')
                      board[i][j] = 'O';
              }
      }
  };

int main()
{
    vector<vector<char> > inp;
    vector<char> inpp;
    inpp.push_back('O');
    inp.push_back(inpp);
    Solution().solve(inp);
    return 0;
}
