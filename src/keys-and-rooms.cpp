class Solution {
public:
    void dfs(int cur, vector<vector<int>>& rooms, vector<bool>& f) {
        //cout << "cur: " << cur << endl;
        //for (auto i:f) cout << i << ' ' ; cout << endl;
        f[cur] = true;
        
        for (int i=0; i<rooms[cur].size(); ++i) {
            int j = rooms[cur][i];
            if (f[j]) continue;
            dfs(j, rooms, f);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size() - 1;
        if (N<=1) return true;
        vector<bool> f;
        f.resize(N+1);
        f[0] = true;
        for (int i=1; i<f.size(); ++i) f[i] = false;
        
        dfs(0, rooms, f);
        for (auto i:f) if (i == false) return false;
        return true;
    }
};
