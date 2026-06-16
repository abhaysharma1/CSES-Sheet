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
        for (int j = i + 1; j < n; j++) {
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                int sum = arr[i].first + arr[j].first + arr[k].first + arr[l].first;
                if (sum == x) {
                    cout << arr[i].second << " " << arr[j].second << " " << arr[k].second << " "
                         << arr[l].second;
                    return 0;
                } else if (sum < x) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
