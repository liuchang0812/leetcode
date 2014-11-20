class MinStack {
public:
    void push(int x) {
        Q.push(x);
        if (minQ.empty() ||
            x <= minQ.top())
            minQ.push(x);
    }

    void pop() {
        if (Q.empty())return;
        if(Q.top() == minQ.top())
            minQ.pop();
        Q.pop();
    }

    int top() {
        return Q.top();
    }

    int getMin() {
        return minQ.top();
    }
private:
    stack<int> Q, minQ;
};
