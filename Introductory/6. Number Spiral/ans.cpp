#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        long long layer = max(x, y);

        long long min = 1ll * (1ll * layer - 1) * (1ll * layer - 1);

        long long offset;

        if (layer % 2 == 0) {
            offset = x + (layer - y);
        } else {
            offset = y + (layer - x);
        }

        cout << min + offset<<" ";
    }
}
