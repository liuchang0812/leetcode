class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end());
		
		vector<int> f(envelopes.size());
		int ans = 0;
		for (int i=0; i<envelopes.size(); ++i)
		{
			int ret = 0;	
			for (int j=0; j<i; ++j)
			{
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
					ret = max(ret, f[j]);
			}
			f[i] = ret + 1;
			ans = max(ans, f[i]);
		}
		return ans;
    }
};
