class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        GenIncPos(A, n);
        int pos1 = IncPos[IncPos.size()-1];
        int ans = GetAns(A, n , IncPos);
        //cout <<"pos: "<< pos1 << " ans "<< ans << endl;
        reverse(A, A+n);
        GenIncPos(A, n);
        int pos2 = IncPos[IncPos.size()-1];
        ans += GetAns(A, n, IncPos);
        
        //cout <<"pos: "<< pos2 << " ans "<< ans << endl;
        pos1 = n - pos1 - 1;
        ans += GetWater(pos2, pos1, A);
        
        //cout <<"pos: "<< pos1 << " ans "<< ans << endl;
        return ans;
    }
private:
    vector<int> IncPos;
    void GenIncPos(int A[], int n) {
        IncPos.clear();
        int pre = A[0]; IncPos.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (A[i] > pre) {
                IncPos.push_back(i);
                pre = A[i];
            }
        }
    }
    int GetWater(int i, int j, int A[]) {
        int tmp = 0;
        int high = min(A[i], A[j]);
        for (int k = i+1; k<j; k++)
            tmp += high - A[k];
        return tmp;
    }
    int GetAns(int A[], int n, vector<int> &incpos) 
    {
        int ans = 0;
        for (int i = 0;i < incpos.size() - 1; i++)
        {
            ans += GetWater(incpos[i], incpos[i+1], A);
        }
        return ans;
    }
    
};
