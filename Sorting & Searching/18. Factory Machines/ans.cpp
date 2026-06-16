#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isPossible(vector<long long>& arr, long long mid, long long t) {
    long long products = 0;
    for (long long i = 0; i < arr.size(); i++) {
        products += mid / arr[i];
        if (products >= t) return true;
    }

    return products >= t;
}

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long high = *max_element(arr.begin(), arr.end()) * t;
    long long low = 0;

    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(arr, mid, t)) {
            ans = min(mid, ans);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
}
