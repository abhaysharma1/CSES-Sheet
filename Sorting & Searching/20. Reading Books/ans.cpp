#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long& i : arr) {
        cin >> i;
    }

    long long total = accumulate(arr.begin(), arr.end(), 0LL);

    long long maximim = *max_element(arr.begin(), arr.end());

    cout << max(total, 2 * maximim);

    
}
