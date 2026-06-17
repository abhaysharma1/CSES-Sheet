#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n), dept(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        cin >> dept[i];
    }

    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    long long i = 0, j = 0, ans = 0, curr = 0;

    while (i < n && j < n) {
        if (arr[i] < dept[j]) {
            curr++;
            i++;
        } else {
            curr--;
            j++;
        }
        ans = max(ans, curr);
    }

    cout << ans;

    return 0;
}
