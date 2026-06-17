#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, x;
    cin >> n >> x;
    map<long long, long long> mp;

    bool flag = false;

    for (long long i = 0; i < n; i++) {
        long long p;
        cin >> p;
        if (mp.find(x - p) != mp.end()) {
            cout << i + 1 << " " << mp[x - p] + 1;
            flag = true;
            return 0;
        }
        mp[p] = i;
    }

    if (!flag) {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
