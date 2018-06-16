class Solution {
public:
    string pushDominoes(string dominoes) {
 	int n = dominoes.size();
	string ans(n, '.');
	int lft = 0;
	int withForce = false;
	int cur = lft;

	while (lft < n) {
		while (cur < n && dominoes[cur] == '.') ++cur;
		if (cur >= n) break;
        //cout << lft << ' ' << cur << ' ' << withForce<< endl;
		if (dominoes[cur] == 'L') {
			if (withForce) {
				int bg = lft;
				int rt = cur;
				while (bg < rt) {
					ans[bg] = 'R';
					ans[rt] = 'L';
                    ++bg;
                    --rt;
				}
				if (bg == rt) ans[bg] = '.';
			} else {
				for (int i=lft; i<=cur; ++i)
					ans[i] = 'L';
			}
			withForce = false;
			lft = cur+1;
            cur = lft;
		} else {
			if (withForce) {
				for (int i=lft; i<cur; ++i)
					ans[i] = 'R';
			} else {
				for (int i=lft; i<cur; ++i)
					ans[i] = '.';
			}
			lft = cur;
			cur = lft+1;
            withForce = true;
		}
	}

	if (lft < n) {
		if (withForce) for (int i=lft; i<n; ++i) ans[i] = 'R';
		else for (int i=lft; i<n; ++i) ans[i] = '.';
	}
	return ans;
    }
};
