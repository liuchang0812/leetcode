class Solution {
public:
	inline int toint(char c) {
    	if (c == 'A') return 0;
    	if (c == 'C') return 1;
    	if (c == 'T') return 2;
    	if (c == 'G') return 3;
		}
    int tointbase4(string &s) {
        int ans = 0;
        for (int i = 0;i < s.size(); i++)
            {
                ans = ans * 4 + toint(s[i]);
            }
        return ans;
    }
    vector<string> findRepeatedDnaSequences(string s) {
  
        vector<string> ans;
        if ( s == "" or s.size() < 10 ) return ans;
   

        
        bool occ[1050000] ;
        bool ansed[1050000];
        memset(occ, 0, sizeof occ);
        memset(ansed, 0, sizeof ansed);
        
        string sub_str;
        for (int i=0; i < s.size() - 9; i++)
        {
            sub_str = s.substr(i, 10);
            if (occ[tointbase4(sub_str)] && ansed[tointbase4(sub_str)] == 0) {
                ans.push_back(sub_str);
                ansed[tointbase4(sub_str)] = 1;
              
            }
            else {
                occ[tointbase4(sub_str)] = 1;
            }
        }
        return ans;
    }
};
