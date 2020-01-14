class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> rightLarge = {-1};
        int maxv = -1;
        for (auto p=arr.size()-1; p>0; --p) {
            maxv = max(maxv, arr[p]);
            rightLarge.push_back(maxv);
            //cout << maxv << endl;
        }
        reverse(rightLarge.begin(), rightLarge.end());
        
        return rightLarge;
    }
};
