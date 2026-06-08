#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        long long sqr = (k) * (k);
        long long total = (sqr * (sqr - 1)) / 2;

        long long attPos = 2 * ((k - 1) * (k - 2)) * 2;

        cout << total - attPos << endl;
    }

    return 0;
}
