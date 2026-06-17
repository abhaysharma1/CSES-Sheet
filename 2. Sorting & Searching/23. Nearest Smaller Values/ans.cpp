#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    stack<long long> stk;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        while (!stk.empty() && arr[stk.top()] >= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            cout << stk.top() + 1 << " ";
        } else {
            cout << 0 << " ";
        }
        stk.push(i);
    }

    return 0;
}
