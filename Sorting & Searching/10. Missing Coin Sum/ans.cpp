#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long reachable = 0;

    for (long long i = 0; i < n; i++) {
        if (arr[i] <= reachable + 1) {
            reachable += arr[i];
        } else {
            cout << reachable + 1;
            return 0;
        }
    }

    cout << reachable + 1;

    return 0;
}
