#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long limit = 1 << n;

    for (int i = 0; i < limit; i++) {
        long long num = i ^ (i >> 1);
        long long mask = 1 << (n - 1);
        long long bitLimit = n;
        while (bitLimit--) {
            if (mask & num) {
                cout << 1;
            } else {
                cout << 0;
            }
            mask = mask >> 1;
        }
        cout << endl;
    }

    return 0;
}
