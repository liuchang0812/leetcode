
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
        vector< vector<int> > ans;
        for (size_t i=0; i<n; i++)
            ans.push_back(vector<int>(n));
        if (n==0) return ans;
        
        
        int d = 0, posx = 0, posy = 0;
        int num = 1;
        ans[0][0] = 1;
        while (num < n*n)
        {
            int nextx, nexty;
            nextx = posx + dx[d];
            nexty = posy + dy[d];
            //cout << "update ("<<nextx<<","<<nexty<<")"<<endl;
            while(  (nextx < 0 || nextx >= n ||
                     nexty < 0 || nexty >= n ||
                     ans[nextx][nexty] != 0))
            {
                d++; d%=4;
                nextx = posx + dx[d];
                nexty = posy + dy[d];
            //    cout << "update ("<<nextx<<","<<nexty<<")"<<endl;
            }
		    //	cout << "choose ("<<nextx<<","<<nexty<<")"<<endl<<endl;
            ans[nextx][nexty] = ++num;
            posx = nextx;
            posy = nexty;
        } 
        return ans;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};
