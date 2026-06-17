#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<long long, long long> mp;
    mp[0] = 1;

    long long currSum = 0, ans = 0;

    for (long long i = 0; i < n; i++) {
        currSum += arr[i];
        ans += mp[((currSum % n) + n) % n];
        mp[((currSum % n) + n) % n]++;
    }

    cout << ans;

    return 0;
}
