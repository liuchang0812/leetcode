#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> lens;
        vector<string> ans;
        for (auto i:words)
            lens.push_back(i.size());

        vector<int> lastOne;
        int cur = 0;
        for (size_t i=0; i<lens.size(); i++)
        {
            int last;
            if (lastOne.size() == 0)
                last = -1;
            else
                last = lastOne.back();

            if (cur + lens[i] + (i-last-1) > maxWidth)
            {
                lastOne.push_back(i-1);
                cur = lens[i];
            }
            else
            {
                cur += lens[i];
            }
            
       }
          map<int, int> lastMap;
          for(auto i:lastOne)
          {
              lastMap[i] = true;
              cout << "last " << i << endl;
          }

          vector<string> s;
          for (size_t i=0; i<words.size(); i++)
          {
              s.push_back(words[i]);
              if (lastMap[i])
              {
                  int sumLen = 0;
                  for (auto i:s) sumLen += i.size();
                  int del = maxWidth - sumLen;
                  int num = s.size() -1;
                  int spaceNum, spaceMod;
                  if (num == 0)
                  {
                      spaceNum = del;
                      spaceMod = 0;
                  }
                  else
                  {
                      spaceNum = del/num;
                      spaceMod = del%num;
                  }
                  cout << spaceNum << ' ' << spaceMod << endl;
                  string tmp;
                  for (int i=0; i<s.size(); i++)
                  {
                      tmp += s[i];
                      if (i!=s.size()-1)
                      tmp += string(spaceNum, ' ');
                      
                      if (spaceMod>0){
                          tmp += ' ';
                          spaceMod --;
                      }
                  }
                  tmp.resize(maxWidth,' ');
                  cout << tmp << endl;
                  ans.push_back(tmp);
                  s.clear();
              }
          }

          if (!s.empty())
          {
              string tmp;
              for (int i=0; i<s.size(); ++i)
              {
                  tmp += s[i];
                  if (i!=s.size()-1)
                  tmp += ' ';
              }
              tmp.resize(maxWidth, ' ');
              ans.push_back(tmp);
              
  
                  s.clear();

          }

          return ans;
      }
  };

void pnt(const vector<string> s)
{
    for(auto i:s)
        cout << i << endl;
}

int main()
{
    string s;
    Solution sol;
    vector<string> inp;
    int n;
    cin >> n;
    while (cin >> s)
    {
        inp.push_back(s);
    }

    pnt(sol.fullJustify(inp, n));
}
