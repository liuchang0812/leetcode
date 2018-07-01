class Solution {
public:
    bool buddyStrings(string A, string B) {
 	if (A.size() != B.size()) return false;
	vector<int> diff;
	for (int i=0; i<A.size(); ++i) {
	    if (A[i] != B[i]) diff.push_back(i);
	}

	if (diff.size() != 2 && diff.size() != 0) return false;

	if (diff.size() == 2) {
		if (A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]])
			return true;
		else 
			return false;
	} else {
		int chr2cnt[26];
		memset(chr2cnt, 0, sizeof chr2cnt);
		for (int i=0; i<A.size(); ++i) 
			++ chr2cnt[A[i] - 'a']; 

		for (int i=0; i<26; ++i)
			if (chr2cnt[i] >= 2) return true;
		return false;
	}
    }
};
