class Queue {
public:

  void push(int x) {
    _data.push(x);
  }

  void pop(void) {
    stack<int> tmp;
    while (!_data.empty()) {
      tmp.push(_data.top());
      _data.pop();
    }

    tmp.pop();

    while (!tmp.empty()) {
      _data.push(tmp.top());
      tmp.pop();
    }
    
  }

  int peek(void) {
    int ans;
    stack<int> tmp;
    while (!_data.empty()) {
      tmp.push(_data.top());
      _data.pop();
    }

    ans = tmp.top();

    while (!tmp.empty()) {
      _data.push(tmp.top());
      tmp.pop();
    }
    return ans;
  }

  bool empty(void) {
    return _data.empty();
  }
private:
  stack<int> _data;
};
