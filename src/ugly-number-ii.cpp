

class Solution {
public:
    bool isUgly(int n)
    {
        if (n == 1) return true;

        while (n%2==0) n/=2;
        while (n%3==0) n/=3;
        while (n%5==0) n/=5;
        return n == 1;
    }

    int nthUglyNumber(int n) {
        map<int, bool> exist;

        long long factor[] = {2,3,5};
        vector<long long> uglyNumbers; int index=0;
        uglyNumbers.push_back(1);
        exist[1] = true;
        while (true)
        {
            if(index == n-1) return uglyNumbers[n-1];
            for (auto i:factor)
            {
                if (exist[i*uglyNumbers[index]]) continue;
                //uglyNumbers.push_back(i*uglyNumbers[index]);
                int j = uglyNumbers.size()-1;
                while (j>=0 && uglyNumbers[j] > i*uglyNumbers[index])
                    j--;
                uglyNumbers.insert(uglyNumbers.begin() + j + 1, i*uglyNumbers[index]);
                exist[i*uglyNumbers[index]] = true;
            }
            index ++;
            //sort(uglyNumbers.begin(), uglyNumbers.end());
        }
        return 1;
    }
};
