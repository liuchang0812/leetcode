class Solution {
public:
    
    string decodeString(string str)
{
    // s -> t

    string src = str+ "$";
    stack<char> chars;
    stack<int> ints;
    int pre = -1;

    for (int i=0; i<src.size(); ++i)
    {
        if (src[i] <= 'z' && src[i] >= 'a')
        {
            chars.push(src[i]);
        }
        else if (src[i] <= '9' && src[i] >= '0')
        {
            if (pre == -1)
            {
                pre = src[i] - '0';
            }
            else
            {
                pre = pre * 10 + src[i] -'0';
            }
        }
        else if (src[i] == '[')
        {
            ints.push(pre);
            pre = -1;

            chars.push(src[i]);
        }

        else if (src[i] == ']')
        {
            string tmp;

            while (!chars.empty())
            {
                char c = chars.top(); chars.pop();
                if (c == '[') break;
                tmp = c + tmp;
            }
            int dup = ints.top(); ints.pop();
            for (int i=0; i<dup; ++i)
            {
                for (int i=0; i<tmp.size(); ++i)
                {
                    chars.push(tmp[i]);
                }
            }
        }
        else if (src[i] == '$')
        {
            string tmp;
            while (!chars.empty())
            {
                tmp = chars.top() + tmp; chars.pop();
            }
            return tmp;
        }
    }
    return "";
}

};
