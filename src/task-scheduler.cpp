class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
 	// 1 2 3 4, 2
	int cnt[26]; 
	memset(cnt, 0, sizeof cnt);
	for(auto i:tasks) cnt[i-'A'] ++;
	int maxV = 0;
	for (auto i:cnt) maxV = max(maxV, i);
	int t = 0;
	for (auto i:cnt) t += (i == maxV);
	return max(int(tasks.size()), (maxV-1) * (n+1) + t);
    }
};
