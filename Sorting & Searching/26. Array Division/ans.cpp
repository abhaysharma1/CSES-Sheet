#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isPossible(vector<long long>& arr, long long mid, long long x) {
    long long partitions = 1, currSum = 0;
    for (long long i = 0; i < arr.size(); i++) {
        if ((currSum + arr[i]) <= mid) {
            currSum += arr[i];
        } else {
            currSum = arr[i];
            partitions++;
        }
    }
    return partitions <= x;
}

int main() {
    long long n, x;
    cin >> n >> x;

    vector<long long> arr(n);
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = 0;

    while (low <= high) {
        long long mid = low + ((high - low) / 2);
        if (isPossible(arr, mid, x)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
