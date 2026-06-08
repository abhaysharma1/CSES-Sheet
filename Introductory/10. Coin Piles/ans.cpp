#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1, n2;
        cin >> n1 >> n2;

        if ((n1 + n2) % 3 == 0) {
            if (n1 > n2 * 2 || n2 > n1 * 2) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}
