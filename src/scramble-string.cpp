class Solution {
public:
    map<pair<string, string> , bool > cache;
    bool cmp(string s1, string s2)
    {   

        if (cache.find(make_pair(s1,s2)) != cache.end())
            return cache[make_pair(s1,s2)];

        if (s1.size() != s2.size())
        {   
            cache[make_pair(s1, s2)] = false;
            return false;
        }
        if (s1 == s2)
        {   
            cache[make_pair(s1, s2)] = true;
            return true;
        }

        bool ret;
        if ( s2.size() == 1)
        {   
            if(  s1 == s2)
                ret =  true;
            else
                ret =  false;
            cache[make_pair(s1, s2)] = ret;
            return ret;
        }

        {   
            for (int mid = 1; mid < s1.size(); mid++)
            {
             bool ret =  cmp(s1.substr(0, mid), s2.substr(0, mid)) && cmp(s1.substr(mid), s2.substr(mid)) ||
                    cmp(s1.substr(0, mid), s2.substr(s2.size()-mid)) && cmp(s1.substr(mid), s2.substr(0, s2.size()-mid));
             if (ret == true)
             {   
                 cache[make_pair(s1, s2)] = true;
                 return true;
             }
            }
            cache[make_pair(s1, s2)] = false;
            return false;
        }
    }
    bool isScramble(string s1, string s2) {
        return cmp(s1, s2);
    }
};
