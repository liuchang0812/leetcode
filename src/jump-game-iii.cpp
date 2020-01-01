class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> _reach;
        _reach.resize(arr.size());
        _reach[start] = true;
        bool delta = true;
        while (delta) {
            delta = false;
            
            for (int i=0; i <arr.size(); ++i) {
                if (_reach[i]) {
                    int l = i-arr[i];
                    int r = i+arr[i];
                    if (l>=0 && !_reach[l]) {
                        delta = true;
                        _reach[l] = true;
                    }
                    if (r < arr.size() && !_reach[r]) {
                        delta = true;
                        _reach[r] = true;
                    }
                }
            }
        }
        
        for (int i=0;i<arr.size();++i)
            if (arr[i] == 0 && _reach[i] == true)
                return true;
        return false;
    }
};
