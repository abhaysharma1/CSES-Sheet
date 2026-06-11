#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void rec(int n, int from, int aux, int to) {
    if (n == 1) {
        ans.push_back({from, to});
        return;
    }

    rec(n - 1, from, to, aux);
    ans.push_back({from, to});
    rec(n - 1, aux, from, to);
}

int main() {
    int n;
    cin >> n;

    rec(n, 1, 2, 3);

    cout << ans.size() << endl;

    for (auto& i : ans) {
        for (int p : i) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}
