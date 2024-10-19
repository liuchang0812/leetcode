class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        

        stack<int> indexs;
        int ans = 0;

        indexs.push(-1);

        for (int i=0; i<heights.size(); ++i) {
            // cout << "num " << i << endl;
            if (indexs.top() == -1 || heights[indexs.top()] <= heights[i]) {
                indexs.push(i);
            } else {
                while (indexs.top() != -1 && heights[indexs.top()] > heights[i]) {
                    int v = indexs.top();
                    if (v != -1) {
                        indexs.pop();
                        ans = max(ans, heights[v] * (i-indexs.top() - 1));
                        //cout << v << ' ' << indexs.top() << ' ' << ans << endl;
                    } else {
                        break;
                    }
                }
                indexs.push(i);
            }
        }

        int sz= heights.size();
        while (!indexs.empty()) {
                    int v = indexs.top();
                    if (v != -1) {
                        indexs.pop();
                        ans = max(ans, heights[v] * (sz-indexs.top() - 1));
                        // cout << v << ' ' << ans << endl;

                    }
                    else {
                        break;
                    }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int col = matrix[0].size();
        vector<int> heights;
        for (int i=0; i<col; ++i) heights.push_back(0);

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<col; ++j) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else 
                    ++heights[j];
            }
            for (int c:heights) cout << c << ' ' ; cout << endl;
            auto r = largestRectangleArea(heights);
            cout << i << ' ' << r << ' ' << ans << endl;
            ans = max(ans, r);
        }
        return ans;
    }
};
