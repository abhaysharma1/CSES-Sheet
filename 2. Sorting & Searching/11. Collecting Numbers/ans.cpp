#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    map<long long, long long> mp;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    long long ans = 0;
    long long lastIdx = n;

    for (long long i = 1; i <= n; i++) {
        long long currIdx = mp[i];
        if (currIdx < lastIdx) {
            ans++;
        }
        lastIdx = currIdx;
    }

    cout << ans;

    return 0;
}
