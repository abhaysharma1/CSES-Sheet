#include <algorithm>
#include <climits>
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
    vector<pair<long long, long long>> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<pair<long long, long long>> dup(arr.begin(), arr.end());
    map<pair<long long, long long>, pair<long long, long long>> mp;

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        if (a.first < b.first || (a.first == b.first && a.second > b.second)) return true;
        return false;
    });

    // Contained by another range
    long long maxLimit = LLONG_MIN;

    for (long long i = 0; i < n; i++) {
        if (arr[i].second <= maxLimit) {
            mp[{arr[i].first, arr[i].second}] = {1, 0};
        } else {
            mp[{arr[i].first, arr[i].second}] = {0, 0};
        }
        maxLimit = max(maxLimit, arr[i].second);
    }

    maxLimit = LLONG_MAX;
    // contains another range
    for (long long i = n - 1; i >= 0; i--) {
        if (arr[i].second >= maxLimit) {
            mp[{arr[i].first, arr[i].second}] = {mp[{arr[i].first, arr[i].second}].first, 1};
        } else {
            mp[{arr[i].first, arr[i].second}] = {mp[{arr[i].first, arr[i].second}].first, 0};
        }
        maxLimit = min(maxLimit, arr[i].second);
    }
    for (long long i = 0; i < n; i++) {
        cout << mp[{dup[i].first, dup[i].second}].second << " ";
    }

    cout << endl;

    for (long long i = 0; i < n; i++) {
        cout << mp[{dup[i].first, dup[i].second}].first << " ";
    }
}
