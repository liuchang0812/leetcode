class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> mapping;
        for (int i=0;i <B.size(); ++i) 
            mapping[B[i]] = i;
        vector<int> ans;
        for (int i=0; i<A.size(); ++i)
            ans.push_back(mapping[A[i]]);
        return ans;
    }
};
