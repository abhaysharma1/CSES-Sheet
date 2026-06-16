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
    vector<pair<long long, long long>> movies(n);
    for (long long i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](auto& a, auto& b) { return a.second < b.second; });

    long long maxi = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
        if (movies[i].first >= maxi) {
            maxi = movies[i].second;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
