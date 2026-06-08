#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long currSum = 0;
    for (int i = 0; i < n-1; i++)
    {
        int p;
        cin >> p;
        currSum += p;
    }

    long long expectedSum = (n * (n + 1)) / 2;

    cout << expectedSum - currSum;

    return 0;
}
