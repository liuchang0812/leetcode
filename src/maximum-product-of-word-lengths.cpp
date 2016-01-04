#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Solution {
public:
    bool f[1505][1505] = {0,};
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        cerr << "size " << n << endl;
        if (n == 0) return 0;
        cerr << "init f" << endl;
        // memset(f, 0, sizeof f);
        
        int contains[1505][26] = {0,};
        // memset(contains, 0, sizeof contains);
        for (int i = 0; i < n; ++i)
        {
            for (auto c:words[i])
            {
                contains[i][c-'a'] = 1;
            }
        }
        cerr << "finished contains" << endl; 
        for (char i = 'a'; i <= 'z'; ++i)
        {
            vector<int> duplicates;
            
            for (int j=0; j<n; ++j)
            if (contains[j][i-'a'])
                duplicates.push_back(j);
            cerr << "dup of " << i << ' ' << duplicates.size() << endl; 
            for (int j=0; j <duplicates.size(); ++j)
                for (int k=0; k<duplicates.size(); ++k)
                f[duplicates[j]][duplicates[k]] = 1;
        }
        int sizes[n];
        for (int i=0; i<n; ++i)
            sizes[i] = words[i].size();
            
        int ans = 0;
        for (int i=0; i < n; ++i)
            for (int j=0; j<n; ++j)
            {
                if (f[i][j] == 0 && i!=j)
                    ans = max(ans, int(sizes[i] * sizes[j]));
            }
        return ans;
    }
};

int main()
{
    string s = "";
    vector<string> inp;
    ifstream cin;
    cin.open("input.txt");
    while (cin >> s)
    {
        inp.push_back(s);
    }
    cerr << inp.size() << endl;
    Solution().maxProduct(inp);
    return 0;
}
