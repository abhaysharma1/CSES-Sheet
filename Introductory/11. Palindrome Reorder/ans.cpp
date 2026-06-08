#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> count(26, 0);

    for (char c : s) {
        count[c - 'A']++;
    }

    string ans = "";

    char odd = '#';

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            if (odd == '#') {
                odd = (char)(i + 'A');
            } else {
                cout << "NO SOLUTION";
                odd = '&';
                break;
            }
        }
    }

    if (odd != '&') {
        string left = "", middle = "", right = "";
        if (odd != '#') {
            for (int i = 0; i < count[odd - 'A']; i++) {
                middle += odd;
            }
            count[odd - 'A'] = 0;
        }

        for (int i = 0; i < 26; i++) {
            int div = count[i] / 2;
            for (int j = 0; j < div; j++) {
                right += (char)(i + 'A');
            }
        }

        left = right;
        reverse(right.begin(), right.end());
        cout << left + middle + right;
    }

    return 0;
}
