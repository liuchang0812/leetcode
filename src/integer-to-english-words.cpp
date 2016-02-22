class Solution {
  public:
      map<int, string> num2str;
      vector<string> bases;
      void init()
      {
          num2str[0] = "";
          num2str[1] = "One";
          num2str[2] = "Two";
          num2str[3] = "Three";
          num2str[4] = "Four";
          num2str[5] = "Five";
          num2str[6] = "Six";
          num2str[7] = "Seven";
          num2str[8] = "Eight";
          num2str[9] = "Nine";
          num2str[10] = "Ten";
          num2str[11] = "Eleven";
          num2str[12] = "Twelve";
          num2str[13] = "Thirteen";
          num2str[14] = "Fourteen";
          num2str[15] = "Fifteen";
          num2str[16] = "Sixteen";
          num2str[17] = "Seventeen";
          num2str[18] = "Eighteen";
          num2str[19] = "Nineteen";
          num2str[20] = "Twenty";
          num2str[30] = "Thirty";
          num2str[40] = "Forty";
          num2str[50] = "Fifty";
          num2str[60] = "Sixty";
          num2str[70] = "Seventy";
          num2str[80] = "Eighty";
          num2str[90] = "Ninety";
          
          
          bases.push_back("");
          bases.push_back("Thousand");
          bases.push_back("Million");
          bases.push_back("Billion");
      }

      vector<string> processChunk(int x)
      {
          cout << "process chunk " << x << endl;
          vector<string> ans;
          if (x == 0) return ans;
          if (x >= 100)
          {
              ans.push_back(num2str[x / 100]);
              ans.push_back("Hundred");
              x %= 100;
          }

          if (x > 20)
          {
              ans.push_back(num2str[x / 10 * 10]);
              if (x % 10) ans.push_back(num2str[x%10]);
          }
          else if (x != 0)
          {
              ans.push_back(num2str[x]);
          }
          return ans;
      }
      
      
      string numberToWords(int num) {
          if (num == 0) return "Zero";
          int base=1000;
          init();
          vector<int> chunks;
          int tmp = num;
          while (tmp)
          {
              chunks.push_back(tmp%1000);
              tmp /= 1000;
          }
          vector<string> words;
          for (int i=chunks.size()-1; i>=0; --i)
          {
              vector<string> tmp = processChunk(chunks[i]);
              if (tmp.size() == 0)
                  continue;
              else
              {
                  for (auto s:tmp)
                      words.push_back(s);
                  words.push_back(bases[i]);
              }
          }
          string ans;
          for (auto s:words)
            if (s != "")
              ans = ans + s + ' ';
          ans.resize(ans.size()-1);
          return ans;
      }
  };
