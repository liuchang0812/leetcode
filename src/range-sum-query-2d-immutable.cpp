#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class NumMatrix {
public:
    typedef pair<int, int> pii;
    map<pii, int> sums;
    NumMatrix(vector<vector<int> > &matrix) {
        for (size_t i=0; i<matrix.size(); ++i)
            for (size_t j=0; j<matrix[0].size(); ++j)
            {
                sums[make_pair(i,j)] = sums[make_pair(i-1, j)] + sums[make_pair(i, j-1)] - sums[make_pair(i-1, j-1)] + matrix[i][j];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
       return sums[make_pair(row2, col2)] - sums[make_pair(row2, col1-1)] - sums[make_pair(row1-1, col2)] + sums[make_pair(row1-1, col1-1)]; 
    }
};

int main()
{
    vector<vector<int> > inp;

    vector<int> tmp;
    for (int i=0; i<5; ++i)
        tmp.push_back(i);

    inp.push_back(tmp);
    inp.push_back(tmp);
    inp.push_back(tmp);
    inp.push_back(tmp);
    inp.push_back(tmp);

    NumMatrix numMatrix(inp);
    cout << numMatrix.sumRegion(0, 1, 2, 3) << endl;
    cout << numMatrix.sumRegion(1, 2, 3, 4) << endl;
    return 0;
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
