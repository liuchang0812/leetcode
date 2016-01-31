#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define debug 1

class Solution {
public:
    vector<int> possible;

    void init(string s, const unordered_set<string>& wordDict, unordered_map<int, vector<string> > &pos2strs)
    {
        for (size_t i=0; i<s.size(); ++i)
        {
            for (auto str: wordDict)
            {
                int len = str.size();
                if (i+len > s.size()) continue;

                if (s.substr(i, len) == str)
                {
                    pos2strs[i].push_back(str);
#ifdef debug
                    cout << "pos2str " << i << ' ' << str << endl;
#endif
                }
            }
        }
    }
    
    void dfs(string s, int cur_pos, vector<string>& cur_ans, unordered_map<int, vector<string> >& pos2strs, vector<string>& ans)
    {
#ifdef debug
        cout << cur_pos << ' ' << "s: " << s <<endl;
        cout << "cur ans: " ;
#endif
        for (auto s: cur_ans) cout << s << ' ' ; cout << endl;
        if (cur_pos >= s.size())
        {
            // got one ans
            
            string dummy;
            for (auto s:cur_ans)
                dummy = dummy + s + ' ';
            dummy.resize(dummy.size()-1);
            ans.push_back(dummy);
#ifdef debug
                    cout << "one ans " << dummy <<  endl;
#endif
            return;
        }
        else
        {
            for (auto s2: pos2strs[cur_pos])
            {
                if (cur_pos + s2.size() > s.size()) continue;
                if (possible[cur_pos + s2.size()])
                {
                    cur_ans.push_back(s2);
                    int before = ans.size();
                    dfs(s, cur_pos+s2.size(), cur_ans, pos2strs, ans);

                    cout << before << ' ' << ans.size() << endl;
                    if (ans.size() == before)
                        possible[cur_pos + s2.size()] = false;
                    cur_ans.pop_back();
                }
            }
        }
    }


    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ans;
        unordered_map<int, vector<string> > pos2strs;
        init(s, wordDict, pos2strs);
        possible.resize(s.size()+1);
        fill(possible.begin(), possible.end(), true);
        
        vector<string> cur_ans; 
        dfs (s, 0, cur_ans, pos2strs, ans);
        return ans; 
    }
};


int main()
{
    unordered_set<string> inp;
    string s;

//    s = "catsanddog";
//    inp.insert("cat"); inp.insert("cats"); inp.insert("and"); inp.insert("sand"); inp.insert("dog");
    s = "aaaa";
    inp.insert("a");
    inp.insert("aa");
    inp.insert("aaa");

    Solution().wordBreak(s, inp); 
    return 0;
}
