class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> cnt;
        for(auto i:arr) ++cnt[i];
        int len = arr.size();
        vector<int> _arr;
        for(auto pair:cnt) 
            _arr.push_back(pair.second);
        sort(_arr.begin(), _arr.end());
        int i = _arr.size()-1;
        int _sum = 0, _cnt=0;
        while(i>=0) {
            if (_sum >= len/2) return _cnt;
            _sum += _arr[i];
            --i;
            ++_cnt;
            
        }
        return _cnt;
    }
};
