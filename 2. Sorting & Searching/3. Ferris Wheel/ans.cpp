#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;

    long long left = 0, right = n - 1;

    while (left <= right) {
        if (arr[left] + arr[right] <= x) {
            ans++;
            left++;
            right--;
        } else {
            ans++;
            right--;
        }
    }

    cout << ans;

    return 0;
}
