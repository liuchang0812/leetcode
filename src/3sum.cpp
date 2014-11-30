class Solution {
public:
    map<int, int> Cnt;
    vector<int> Keys;
    vector<vector<int> > Ans;
    vector<int> OneAns;

    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        for (size_t i=0; i<num.size(); ++i) {
            Cnt[num[i]] ++;
        }
        for (map<int,int>::iterator p = Cnt.begin(); p!=Cnt.end(); p++ )
            Keys.push_back(p->first);
            
        for (int i=0;i <Keys.size();i ++)
            for (int j=i; j<Keys.size(); j++)
                {
                    Cnt[Keys[i]] --;
                    Cnt[Keys[j]] --;
                    
                    if (Cnt[Keys[i]] >= 0 &&
                        Cnt[Keys[j]] >= 0 &&
                        0 - Keys[i] - Keys[j] >= Keys[j] &&
                        Cnt[0 - Keys[i] -Keys[j]] >= 1)
                        {
                            vector<int> tmp; 
                            tmp.push_back(Keys[i]);
                            tmp.push_back(Keys[j]);
                            tmp.push_back(0 - Keys[i] - Keys[j]);
                            Ans.push_back(tmp);
                        }
                    Cnt[Keys[i]] ++;
                    Cnt[Keys[j]] ++;
                }
        return Ans;
    }
};
