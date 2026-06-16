#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n, x;
    cin >> x >> n;
    vector<long long> arr(n);
    for (long long& i : arr) {
        cin >> i;
    }

    set<long long> segments;
    multiset<long long> segmentLength;

    segmentLength.insert(x);

    segments.insert(0);
    segments.insert(x);



    for (long long i = 0; i < n; i++) {
        auto right = segments.upper_bound(arr[i]);
        auto left = prev(right);

        auto it = segmentLength.find(*right - *left);

        segmentLength.erase(it);

        long long first = arr[i] - *left;
        long long second = *right - arr[i];

        segments.insert(arr[i]);

        segmentLength.insert(first);
        segmentLength.insert(second);

        cout << *segmentLength.rbegin() << " ";

        segments.insert(arr[i]);
    }

    return 0;
}
