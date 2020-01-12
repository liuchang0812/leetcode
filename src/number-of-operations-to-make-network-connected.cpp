class Solution {
public:
    int ID[100005];
    unordered_map<int, vector<int> > ok;
    
    void dfs(int n, int id, int maxid) {
        //cout << n << ' ' << id << endl;
        ID[n] = id;
        for (int i=0;i<ok[n].size();++i) {
            int _id = ok[n][i];
            if (_id!=n && ID[_id]==-1)
                dfs(_id, id,  maxid);
 
        }
               }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size()+1) return -1;
        
    
        for (int i=0;i<connections.size();++i) {
            int a = connections[i][0];
            int b = connections[i][1];
            ok[a].push_back(b);
            ok[b].push_back(a);
        }
        
         for(int i=0;i<n;++i)ID[i] = -1;
        int curID = 0;
        for (int i=0; i<n; ++i) {
            if (ID[i] == -1) {
                ++curID;
                dfs(i, curID,  n);
            }
        }
        return curID - 1;
    }
};
