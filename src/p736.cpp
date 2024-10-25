// 一个有点儿丑陋的递归下降的 list 表达式解析

class Solution {
public:
    string s;
    int cur = 0;
    map<string, int> env;
    int let() {
        assert(s[cur] == 'l');
        cur += 3;

        while (cur < s.size()) {
            while (s[cur] == ' ')
                ++cur;

            int temp_cur = cur;
            while (isalnum(s[temp_cur]))
                ++temp_cur;
            if (s[temp_cur] == ')')
                return expression();
            if (s[cur] == '(' || s[cur] < 'a' || s[cur] > 'z')
                return expression();

            string tmp;
            while (cur < s.size() && s[cur] != ' ' && s[cur] != ')') {
                tmp += s[cur];
                ++cur;
            }

            int v = expression();
            env[tmp] = v;
        }
        return 0;
    }

    int add() {
        assert(s[cur] == 'a');
        cur += 3;

        while (s[cur] == ' ')
            ++cur;
        int v1 = expression();
        while (s[cur] == ' ')
            ++cur;
        int v2 = expression();
        while (s[cur] == ' ')
            ++cur;
        assert(s[cur] == ')');
        return v1 + v2;
    }

    int mult() {
        assert(s[cur] == 'm');
        cur += 4;

        while (s[cur] == ' ')
            ++cur;
        int v1 = expression();
        while (s[cur] == ' ')
            ++cur;
        int v2 = expression();
        while (s[cur] == ' ')
            ++cur;
        cout << s << ' ' << cur << ' ' << s[cur] << endl;
        assert(s[cur] == ')');
        return v1 * v2;
    }

    int expression() {
        while (cur < s.size() && s[cur] == ' ')
            ++cur;

        if (s[cur] == '(') {
            ++cur;
            int v;
            if (s[cur] == 'l') {
                auto origin_env = env;
                v = let();
                env = origin_env;
            } else if (s[cur] == 'a') {
                v = add();
            } else if (s[cur] == 'm') {
                v = mult();
            } else {
                printf("error %d\n", cur);
                return 0;
            }
            ++cur;
            return v;
        } else {
            bool neg = false;
            if (s[cur] == '-') {
                neg = true;
                ++cur;
            }
            if (s[cur] >= '0' && s[cur] <= '9') {
                int v = 0;
                while (s[cur] >= '0' && s[cur] <= '9') {
                    v *= 10;
                    v += s[cur] - '0';
                    ++cur;
                }
                return neg ? -v : v;
            } else {
                string tmp;
                while (cur <= s.size() && s[cur] != ' ' && s[cur] != ')') {
                    tmp += s[cur];
                    ++cur;
                }
                return env[tmp];
            }
        }
        return 0;
    }

    int evaluate(string ex) {
        s = ex;
        cur = 0;
        env.clear();
        return expression();
    }
};
