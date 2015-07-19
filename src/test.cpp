#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push(1);
    dq.push(2);
    dq.push(4);

    for (auto i = dq.begin(); i != dq.end(); ++i)
    {
        cout << *i << endl;
    }
    return 0;
}
