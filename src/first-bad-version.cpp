// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=0, r=n;
        while (l < r-1)
        {
            int m = l + ((r-l)>>1);
            bool bad = isBadVersion(m);
            if (bad) r = m;
            else l = m;
        }
        return r;
    }
};
