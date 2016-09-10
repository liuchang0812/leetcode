class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int need = 0;
        const int x10 = 0x8;
        const int x110 = 0x6;
        const int x1110 = 0xe;
        const int x11110 = 0x1e;
        
        for (int i=0;i < data.size(); ++i)
        {
            int d = data[i] % 256;
            
            if (!need)
            {
                if (d & (1 << 7))
                {

                    if ((d >> 5) == x110)
                    {
                        need = 1;
                    }
                    else if ((d >> 4) == x1110)
                    {
                        need = 2;
                    }
                    else if ((d >> 3) == x11110)
                    {
                        need = 3;
                    }
                    else 
                    {
                        cout << "expert only 110/1110/11110 but received " << d << endl;
                        return false;
                    }
                }
            }
            else
            {
                if ((d >> 6) == 2)
                {
                    need -= 1;
                }
                else
                {
                    cout << "expect 10xxxxx, but received " << d << " original  " << data[i] << endl;
                    return false;
                }
            }
        }
        return need == 0;
    }
};
