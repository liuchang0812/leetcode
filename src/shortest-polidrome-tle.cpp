class Solution {
public:
    string shortestPalindrome(string s) {
        int pos = s.size()-1;
        while (pos)
        {
            int front = 0;
            int end = pos;
            
            while(front < end && s[front] == s[end])
            {
                front ++;
                end --;
            }
            
            if (end <= front) break;
            else --pos;
        }
        cout << pos << endl;
        string s2 = s.substr(pos+1);
        reverse(s2.begin(), s2.end());
        return s2 + s;
    }
};
