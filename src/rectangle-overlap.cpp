class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1, y1, x2, y2, x3, y3, x4, y4;

        if ( rec2[3] <= rec1[1] ||
             rec2[0] >= rec1[2] ||
             rec2[1] >= rec1[3] ||
             rec2[2] <= rec1[0] )
                return false;
        return true;
    }
};

