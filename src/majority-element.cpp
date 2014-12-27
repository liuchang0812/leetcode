class Solution {
public:
    int majorityElement(vector<int> &num) {
        int MajorityValue = num[0];
        int OccTimes = 1;
        for (size_t i = 1; i < num.size(); i++)
        {
            if (OccTimes == 0) 
            {
                OccTimes = 1;
                MajorityValue = num[i];
            }
            else
            {
                if (num[i] == MajorityValue)
                    OccTimes ++;
                else
                    OccTimes --;
            }
        }
        return MajorityValue;
    }
};
