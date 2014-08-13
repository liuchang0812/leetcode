class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
    
            for (size_t i=0; i< matrix.size(); ++i)
               for (size_t j=0; j< matrix[0].size(); ++j)
               {
                   if (matrix[i][j] != 0) continue;
                   else {
                       for (size_t k=0; k < matrix.size(); k++)
                           matrix[k][j] = matrix[k][j]!=0?INT_MIN+1:0;
                       for (size_t k=0; k< matrix[0].size(); k++)
                           matrix[i][k] = matrix[i][k]!=0?INT_MIN+1:0;
                   }
               }
            for (size_t i=0; i<matrix.size(); ++i)
                for (size_t j=0; j<matrix[0].size(); ++j)
                    if (matrix[i][j] == INT_MIN+1)
                        matrix[i][j] = 0;
        }
};
