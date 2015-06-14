class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        topValue = x;
        Q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmpQ;
        int l = Q.size();
        for (size_t i = 0; i < l-1; ++i)
        {
            int v = Q.front();
            Q.pop();
            tmpQ.push(v);
            topValue = v;
        }
        Q = tmpQ;
    }

    // Get the top element.
    int top() {
        return topValue;
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
private:
    int topValue;
    queue<int> Q;
};
