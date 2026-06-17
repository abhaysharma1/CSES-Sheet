#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long num = 1;

    for(int i = 0; i < n; i++){
        num *= 2;
        num = num % ((long long)1e9 + 7);
    }

    cout << num % ((long long)1e9 + 7);

    return 0;
}
