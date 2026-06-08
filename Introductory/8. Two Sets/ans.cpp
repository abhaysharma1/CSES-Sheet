#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long aggre = (n * (n + 1)) / 2;

    if (aggre % 2 != 0)
        cout << "NO";
    else {
        long long rem = aggre / 2;

        vector<int> first, second;

        for (int i = n; i >= 1; i--) {
            if (i <= rem) {
                first.push_back(i);
                rem -= i;
            } else {
                second.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << first.size() << endl;
        for (int i = 0; i < first.size(); i++) {
            cout << first[i] << " ";
        }
        cout << endl;
        cout << second.size() << endl;
        for (int i = 0; i < second.size(); i++) {
            cout << second[i] << " ";
        }
    }
}
