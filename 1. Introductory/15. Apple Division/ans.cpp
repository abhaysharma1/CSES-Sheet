#include <algorithm>
#include <iostream>
#include <numeric>
#include <climits>
#include <vector>

using namespace std;

long long ans = LLONG_MAX;

void rec(long long curr, long long total, int idx, vector<long long>& arr) {
    if (idx == arr.size()) {
        long long right = total - curr;
        ans = min(ans, abs(right - curr));
        return;
    }

    rec(curr + arr[idx], total, idx + 1, arr);
    rec(curr, total, idx + 1, arr);
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = accumulate(arr.begin(), arr.end(), 0LL);

    rec(0, total, 0, arr);

    cout << ans;
}
