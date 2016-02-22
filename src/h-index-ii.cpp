class Solution {
public:
    int hIndex(vector<int>& citations) {
        //sort(citations.begin(), citations.end());
        
        int len = citations.size();
        
        
        int left = 0;
        int right = len + 1;
        int mid;
        
        while (right > left + 1)
        {
            mid = left + (right - left) / 2;
            if (citations.end() - lower_bound(citations.begin(), citations.end(), mid) >= mid)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
