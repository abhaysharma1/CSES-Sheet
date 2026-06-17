#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long& i : arr) {
        cin >> i;
    }

    multiset<long long> tops;

    for (long long i = 0; i < n; i++) {
        auto it = tops.upper_bound(arr[i]);
        if (it != tops.end()) {
            tops.insert(arr[i]);
            tops.erase(it);
        } else {
            tops.insert(arr[i]);
        }
    }

    cout << tops.size();

    return 0;
}
