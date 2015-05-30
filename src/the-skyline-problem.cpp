class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        map<int, int> hash, r_hash, inserted;
        int R = -1;
        set<int> nums;
        for (size_t i = 0; i < buildings.size(); ++i)
        {
        	int b = buildings[i][0];
        	int e = buildings[i][1];
        	if (R == -1)
        	{
        		R = e;
        	}
        	
			if (b > R + 1)
			{
				nums.insert(R+1);
			}
			nums.insert(b);
			nums.insert(e);
			R = max(R, e);
        }

       for (set<int>::iterator ptr = nums.begin(); ptr != nums.end(); ++ptr)
        {
            static int cnt = 0;
            hash[*ptr] = cnt;
            r_hash[cnt] = *ptr;
            cnt ++;
        }
        
        int high[20005];
        memset(high, 0, sizeof high);
        for (size_t i = 0; i < buildings.size(); i ++)
        {
            int b = hash[buildings[i][0]];
            int e = hash[buildings[i][1]];
            int h = buildings[i][2];
            for (int j = b; j < e; j ++)
                high[j] = max(high[j], h);
        }
        int preh = 0;
        vector<pair<int, int> > ans;
        for (int i = 0; i < 20005; i ++)
        {
            if (high[i] != preh)
            {
                ans.push_back(make_pair(r_hash[i], high[i]));
                preh = high[i];
            }
        }
        return ans;
    }
};
