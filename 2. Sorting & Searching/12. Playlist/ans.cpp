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
    vector<long long> arr(n);
    map<long long, long long> mp;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long left = 0, right = 0, curr = 0, ans = 1;

    while (right < n) {
        mp[arr[right]]++;

        while (mp[arr[right]] != 1) {
            mp[arr[left]]--;
            left++;
        }
        
        curr = right - left + 1;
        ans = max(ans, curr);
        right++;
    }

    cout << ans;

    return 0;
}
