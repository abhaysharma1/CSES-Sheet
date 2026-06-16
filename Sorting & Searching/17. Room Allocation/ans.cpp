#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<tuple<long long, long long, long long>> arr(n);

    for (long long i = 0; i < n; i++) {
        long long arri, dep;
        cin >> arri >> dep;
        get<0>(arr[i]) = arri;
        get<1>(arr[i]) = dep;
        get<2>(arr[i]) = i;
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> hp;

    sort(arr.begin(), arr.end(),
         [](tuple<long long, long long, long long>& a, tuple<long long, long long, long long>& b) { return get<0>(a) < get<0>(b); });

    vector<long long> ans(n);

    long long rooms = 0;

    for (long long i = 0; i < n; i++) {;
        if (hp.size() > 0) {
            auto tp = hp.top();
            if (tp.first < get<0>(arr[i])) {
                hp.pop();
                ans[get<2>(arr[i])] = tp.second;
            } else {
                rooms++;
                ans[get<2>(arr[i])] = rooms;
            }
            hp.push({get<1>(arr[i]), ans[get<2>(arr[i])]});
        } else {
            rooms++;
            hp.push({get<1>(arr[i]), rooms});
            ans[get<2>(arr[i])] = rooms;
        }
    }

    cout << rooms << endl;

    for (long long i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
