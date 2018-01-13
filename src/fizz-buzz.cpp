class Solution {
public:
    string int2str(int i) {
        string ans;
        while (i != 0) {
            ans =  char(i%10 + '0') + ans;
            i /= 10;
        }
        return ans;
    }
    string fizzbuzz(int i) {
        if (i % 15 == 0) return "FizzBuzz";
        else if (i % 3 == 0) return "Fizz";
        else if (i % 5 == 0) return "Buzz";
        return int2str(i);
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i=1; i<=n; ++i) 
            ans.push_back(fizzbuzz(i));
        return ans;
    }
};
