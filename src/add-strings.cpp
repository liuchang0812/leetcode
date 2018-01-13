ss Solution {
public:
    string addStrings(string num1, string num2) {
      string ans = ""; 
      int jw = 0;
      int len = max(num1.size(), num2.size());
      num1 = string( len-num1.size(), '0') + num1;
      num2 = string(len-num2.size(), '0') + num2;
      for (int i=num1.size()-1; i>=0; --i)
      { 
          int s = (num1[i] - '0') + (num2[i] - '0') + jw;
          jw = s / 10;
          ans = char(int('0') + (s % 10)) + ans;
           
      }
        if (jw != 0) ans = char(int('0') + jw) + ans;
      return ans;
    }
};


