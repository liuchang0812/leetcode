class Solution {
public:
    int minimumLength(string s) {
        int totalLen = s.size();
        int front = 0;
        int end = s.size()-1;

        while (s[front] == s[end] && front < end) {
            while (front + 1 < end && s[front+1] == s[front]) ++front;
            while (end - 1 > front && s[end-1] == s[end]) --end;

            ++front;
            --end;
        }
        return max(0, end - front + 1);
    }
};
