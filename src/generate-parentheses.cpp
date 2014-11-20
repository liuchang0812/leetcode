class Solution {
public:
    void printPar(int l, int r, vector<string>& result, char* str, int idx)
    {
        if (l < 0 || r < l) return;
        if (l == 0 && r == 0)
        {
            str[idx] = '\0';
            result.push_back(string(str));
        }
        else
        {
            if (l > 0)
            {
                str[idx] = '(';
                printPar(l-1, r, result, str, idx+1);
            }
            if (r > l)
            {
                str[idx] = ')';
                printPar(l, r-1, result, str, idx+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        char* str = new char[2*n+1];
        printPar(n, n, result, str, 0);
        delete []str;
        return result;
    }
};
