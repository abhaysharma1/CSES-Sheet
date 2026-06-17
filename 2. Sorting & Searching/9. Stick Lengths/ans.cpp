#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    long long total = 0;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long median = arr[n / 2];

    long long ans = 0;

    for (long long i = 0; i < n; i++) {
        long long curr = abs(arr[i] - median);
        ans += curr;
    }

    cout << ans;

    return 0;
}
