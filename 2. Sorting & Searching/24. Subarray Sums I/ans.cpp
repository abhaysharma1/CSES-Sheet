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
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long left = 0, right = 0, currSum = 0, ans = 0;

    while (right < n) {
        currSum += arr[right];
        right++;
        while (left < n && currSum > x) {
            currSum -= arr[left];
            left++;
        }
        if (currSum == x) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
