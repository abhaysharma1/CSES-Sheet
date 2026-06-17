#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = INT_MIN, curr = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        if (curr < 0) curr = 0;
        curr += p;
        ans = max(ans, curr);
    }

    cout << max(ans, curr);

    return 0;
}
