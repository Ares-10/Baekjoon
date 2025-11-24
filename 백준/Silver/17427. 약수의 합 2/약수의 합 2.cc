#include <iostream>

using namespace std;

int main(void)
{
    int n;
    long sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i * (n / i);
    }
    cout << sum << endl;
}