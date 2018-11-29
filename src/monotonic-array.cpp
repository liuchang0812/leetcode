class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int diff = 0;
        for (int i=1; i<A.size(); ++i)
            if (A[i] - A[i-1] == 0) continue;
            else {
                if (diff * (A[i]-A[i-1]) < 0) return false;
                else 
                    diff = A[i] - A[i-1];
            }
        return true;
    }
};
