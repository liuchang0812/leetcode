class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> spans;
        for (int i=0; i<ranges.size(); ++i) {
            if (ranges[i] != 0)
            spans.push_back(make_pair(i-ranges[i], i+ranges[i]));
        }
        sort(spans.begin(), spans.end(), [](pair<int, int> a,pair<int, int> b) {
            return a.first < b.first ||
                    a.first == b.first && a.second <= b.second;
        });
        //for (auto i:spans) cout << i.first << ' ' << i.second << endl;
        
        // merge span
        bool has[100005]; memset(has, 0, sizeof has);
     
           if (spans.size() > 0) {
        int p=0,ml=spans[0].first,mr=spans[0].second;
        
        
     
            
       
        for (int i=1; i<spans.size(); ++i) {
  
            
            if (spans[i].second <= mr) has[i] = false;
            else {
                if (spans[i].first == ml) {
                    //cout << i << "debug" << endl;
                    has[p] = false;
                    p = i;
                    ml = spans[i].first;
                    mr = spans[i].second;
                } else {
                    has[p] = true;
                    p = i; ml = spans[i].first;mr = spans[i].second;   
                }
            }
            
        }
      
        has[p] = true;
           }  
        vector<pair<int, int>> _spans;
        for (int i=0;i<spans.size();++i)
            if (has[i]) _spans.push_back(spans[i]);
        /*
        cout << "=-========"<<endl;
        for (auto i:_spans) cout << i.first << ' ' << i.second << endl;
 cout << "=-========"<<endl;
 */
        int l = 0, r=0;
        int ans = 0;
        int i=0;
        while(i<_spans.size()) {
            int pi = i;
            while(i<_spans.size() && _spans[i].first <= l && _spans[i].second >= r) ++i;
            if (pi == i) return -1;
            if (i==_spans.size()) {
                ++ans;
                r = _spans[i-1].second;
                break;
            }else {
                ++ans;
                l = r = _spans[i-1].second;
                //l = _spans[i-1].first;
            }
            //cout << i << ' ' << ans << ' ' << l << ' ' << r << endl;
            if (l >= n) break;
        }
        /*
        for (int i=0;i<_spans.size();++i) {
            
            if (_spans[i].first <= 0 && _spans[i].second >= to)
            {
                ans = 1;
                to = _spans[i].second;
            } else 
            if (_spans[i].first <= to && _spans[i].second > to && to < n) {
                ++ans;
                to = _spans[i].second;
            }
        }*/
        if (r >= n)
        return ans;
        else return -1;
    }
};
