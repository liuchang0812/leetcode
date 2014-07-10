class Solution{
public:
    enum Operators{
        O_PLUS,
        O_SUB,
        O_MULT,
        O_DIV,
        O_UNKNOW
    };

    Operators GetOperatorsType(string s)
    {
        switch(int(s[0]))
        {
            case int('+'): return O_PLUS;
            case int('-'): return O_SUB;
            case int('*'): return O_MULT;
            case int('/'): return O_DIV;
            default:  return O_UNKNOW;
        }
    }
    int StringToInt(string s)
    {
        int cur = 0;
        for (int i = 0;i <  s.size();i++)
        {
            if (s[i] == '-') continue;
            cur = cur * 10 + (s[i] - '0');
        }
        if (s[0] == '-') cur = cur * -1;
        return cur;
    }

    bool isOperand(string s)
    {
        if (s.size() >= 2) return true;
        if ( s == "+" ||
             s == "-" ||
             s == "*" ||
             s == "/" )
            return false;
        return true;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> _S;
        for (int i = 0;i < tokens.size(); i++)
        {
            
            if (isOperand(tokens[i]))
            {
                _S.push(StringToInt(tokens[i]));
            }
            else
            {
                int lval,rval;
                rval = _S.top();_S.pop();
                lval = _S.top();_S.pop();
                switch(GetOperatorsType(tokens[i]))
                {
                    case O_PLUS: _S.push(lval + rval);break;
                    case O_SUB: _S.push(lval - rval);break;
                    case O_MULT: _S.push(lval*rval);break;
                    case O_DIV: _S.push(lval / rval);break;
                }
            }
        }
        if (!_S.empty())
            return _S.top();
    }
};
