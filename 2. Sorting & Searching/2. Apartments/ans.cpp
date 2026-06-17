#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> desired(n);
    for (long long i = 0; i < n; i++) {
        cin >> desired[i];
    }
    vector<long long> apartments(m);
    for (long long i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    long long i = 0;
    long long j = 0;

    long long ans = 0;

    while (i < n && j < m) {
        long long low = desired[i] - k;
        long long high = desired[i] + k;

        long long aptSize = apartments[j];

        if (aptSize > high) {
            i++;
            continue;
        }

        else if (aptSize >= low && aptSize <= high) {
            i++;
            ans++;
        }
        j++;
    }

    cout << ans;

    return 0;
}
