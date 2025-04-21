class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // 0 5 
        // 4 5
        // [l, r] x
        // nl + x >= lower <= upper
        // nr + x >= lower <= upper
        // 0...5
        // 4...9
        // -3 .. 2
        int nl = lower;
        int nr = upper;
        for (int i=0; i<differences.size(); ++i) {
            int c = differences[i];
            int l = nl + c;
            int r = nr + c;

            nl = min(upper+1, max(l, lower));
            nr = max(lower-1, min(r, upper));
        }
        int res = nr - nl + 1;
        return res > 0 ? res : 0;
    }
};