class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A, E);
        int x2 = min(C, G);
        int ret = 1;
        if (x1 >= x2) ret = 0;
        
        
        int y1 = min(D, H);
        int y2 = max(B, F);
        if (y1 <= y2) ret = 0;
        if (!ret) return (C-A)*(D-B) + (G-E)*(H-F);
        return (C-A)*(D-B) + (G-E)*(H-F) - (x2-x1) * (y1-y2);
    }
};
