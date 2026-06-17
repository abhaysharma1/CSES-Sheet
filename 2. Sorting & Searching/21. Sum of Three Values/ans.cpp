#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) { return a.first < b.first; });

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i].first + arr[j].first + arr[k].first;
            if (sum == x) {
                cout << arr[i].second << " " << arr[j].second << " " << arr[k].second;
                return 0;
            } else if (sum < x) {
                j++;
            } else {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
