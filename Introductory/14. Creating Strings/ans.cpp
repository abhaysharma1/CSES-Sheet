#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;

    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << endl;

    for (string i : ans) {
        cout << i << endl;
    }
}
