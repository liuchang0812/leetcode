class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        bool ok[100][100];
        memset(ok, 0, sizeof ok);
        for (int i=0;i<friends.size(); ++i)
            for (int j=0; j<friends[i].size(); ++j) {
                ok[i][friends[i][j]] = true; 
                ok[friends[i][j]][i] = true;
            }
        queue<int> Q;
        queue<int> L;
        Q.push(id);
        L.push(0);
        
        vector<int> ids;
        map<int, bool> visited;
        visited[id] = true;
        while(!Q.empty()) {
            int _id = Q.front();Q.pop();
            int _lv = L.front();L.pop();
            //cout << "id level: " << _id << ' ' << _lv << endl;
            if (_lv > level)
                break;
            
            if (_lv == level) ids.push_back(_id);
            
            for (int i = 0; i<friends[_id].size(); ++i) {
                //cout << "friend: " << friends[_id][i] << endl;
                if (visited[friends[_id][i]] == false) {
                    Q.push(friends[_id][i]);
                    L.push(_lv+1);
                    visited[friends[_id][i]] = true;
                }
            }
        }
        
        
        vector<pair<string, int>> vcnt;
        map<string, int> cnt;
        for (auto i:ids) {
            for (auto j:watchedVideos[i])
                cnt[j]++;
        }
        for (auto p:cnt)
            vcnt.push_back(make_pair(p.first, p.second));
        sort(vcnt.begin(), vcnt.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.second < b.second ||
                    a.second == b.second && a.first < b.first;
        });
        vector<string> ans;
        for (auto p:vcnt) ans.push_back(p.first);
        return ans;
    }
};
