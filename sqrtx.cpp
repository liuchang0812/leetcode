class Solution {
public:
        int sqrt(int x) {
            long long l=0, r=x,m;
            do
            {
                m = l + (r-l)/2;
                if (m*m == x)
                {
                    return m;
                }
                else if(m*m > x)
                {
                    r = m;
                }
                else
                {
                    l = m ;
                }
            }while (r - 1>l);
            if ((l+1)*(l+1) <= x) return l+1;
            return l;
        }

};
