#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int mxi = 0, curr = 1;
    if (s.length() == 1) {
        mxi = 1;
    }

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            curr++;
        } else {
            curr = 1;
        }
        mxi = max(mxi, curr);
    }

    cout << mxi;

    return 0;
}
