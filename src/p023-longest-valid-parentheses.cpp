class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, char>> st;

        int ans = 0;
        for (auto c : s) {
            bool boom = false;

            if (c == '(') {
                st.push({1, '('});
            } else {
                int val = 0;
                if (st.empty()) { st.push({1, ')'}); continue; }
                while (!st.empty()) {
                    auto v = st.top();
                    if (v.first == 1 && v.second == ')') {
                        break;
                    } else if(v.first == 1 && v.second == '(') {
                            st.pop();
                            val += 2;
                            boom = true;
                            break;
                    } else {
                        st.pop();
                        val += v.first;
                    }
                }
                if (val) {
                    st.push({ val, ' '});
                }
                if (!boom) st.push({ 1, ')'});
            }
        }

        int cur = 0;
        while (!st.empty()) {
            auto v = st.top(); st.pop();
            cout << v.first << ' ' << v.second << endl;
            if (v.first != 1) {
                cur += v.first;
                ans = max(ans, cur);
            }
            else {
                cur = 0;
            }
        }
        return ans;
    }
};
