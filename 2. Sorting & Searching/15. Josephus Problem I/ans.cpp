#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    list<long long> lst;
    for (long long i = 1; i <= n; i++) {
        lst.push_back(i);
    }

    auto it = next(lst.begin());
    if (it == lst.end()) {
        it = lst.begin();
    }

    while (!lst.empty()) {
        cout << *it << " ";

        it = lst.erase(it);

        if (lst.empty()) {
            break;
        }

        if (it == lst.end()) {
            it = lst.begin();
        }

        it++;
        
        if (it == lst.end()) {
            it = lst.begin();
        }
    }

    return 0;
}
