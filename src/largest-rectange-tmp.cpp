#include <stack>
#include <vector>
#include <iostream>
using namespace std;
int largestRectangleArea(vector<int> &h) {  
     stack<int> S;  
     h.push_back(0);  
     int sum = 0;  
     for (int i = 0; i < h.size(); i++) {  
          if (S.empty() || h[i] > h[S.top()]) S.push(i);  
          else {  
               int tmp = S.top();  
               S.pop();  
                sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));  
                i--;  
           }  
      }  
      return sum;  
 } 


int main()
{
    vector<int> inp;

    for (int i=0; i<20000; ++i)
    {
        inp.push_back(i);
    }
    cout << largestRectangleArea(inp)<<endl;
    return 0;
}
