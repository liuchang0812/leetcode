class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return true;
        
        int x = matrix.size(); int y = matrix[0].size();
        int row = 0; int col = y-1;
        
        while (row < x && col >= 0)
        {
            if (matrix[row][col] == target) return true;
            
            if (matrix[row][col] > target) col --;
            else row ++;
        }
        return false;
    }
};
