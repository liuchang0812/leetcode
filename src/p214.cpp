class Solution
{
public:
    vector<int> next(const string &s)
    {
        vector<int> res;
        res.resize(s.size());
        res[0] = 0;

        for (int i = 1; i < s.size(); ++i)
        {
            int j = res[i - 1];

            while (j > 0 && s[j] != s[i])
                j = res[j - 1];
            if (s[i] == s[j])
                res[i] = j + 1;
            else
                res[i] = j;
        }

        return res;
    }

    string shortestPalindrome(string s)
    {
        auto s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        auto ss = s + "#" + s_rev;
        cout << s << ' ' << ss << endl;
        auto next_vec = next(ss);
        for (auto i : next_vec)
            cout << i << ' ';
        cout << endl;
        auto v = next_vec.back();
        auto rs = s.substr(v);
        reverse(rs.begin(), rs.end());
        return rs + s;
    }
};
