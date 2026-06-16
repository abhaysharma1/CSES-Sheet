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
    vector<pair<long long, long long>> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) { return a.first < b.first; });

    long long ans = 0;
    long long time = 0;

    for (long long i = 0; i < n; i++) {
        time += arr[i].first;
        ans += (arr[i].second - time);
    }

    cout << ans;

    return 0;
}
