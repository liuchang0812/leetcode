#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void dfs(vector<int>& arr, int pos) {
    if (pos - 1 >= 0 && arr[pos-1] > arr[pos])
        swap(arr[pos-1], arr[pos]);
    if (pos+1 < arr.size() && arr[pos+1] > arr[pos])
        swap(arr[pos], arr[pos+1]);

    if (pos-2>=0 && arr[pos-1] > arr[pos-2])
        dfs(arr, pos-2);
}

void PeakSort(vector<int>& arr) {
    int s = arr.size();
    for (int i=0; 1+2*i < s; i++) {
        dfs(arr, 2*i+1);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9, 8, 8};
    PeakSort(arr);

    for (auto i: arr)
        cout << i << ' ';
    cout << endl;
}
