#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> maxPrice(m);
    multiset<long long> st;

    for (long long i = 0; i < n; i++) {
        long long p;
        cin >> p;
        st.insert(p);
    }

    for (long long i = 0; i < m; i++) {
        cin >> maxPrice[i];
    }

    for (long long i = 0; i < m; i++) {
        auto it = st.upper_bound(maxPrice[i]);
        if (it == st.begin()) {
            cout << -1 << endl;
            continue;
        }
        it--;
        cout << *it << endl;
        st.erase(it);
    }

    return 0;
}
