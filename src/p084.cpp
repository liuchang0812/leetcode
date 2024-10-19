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
};
