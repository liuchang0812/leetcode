class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int posx = 0, posy = 0;
        int n = matrix.size(); 
        int m = matrix[0].size();
        
        do {
            if (matrix[posx][posy] == target) return true;
            if (posx + 1 < n && matrix[posx+1][posy] <= target) posx ++;
            else posy++;
        } while (posx < n && posy < m);
        return false;
    }
};
