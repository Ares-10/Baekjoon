#include <iostream>

using namespace std;

int main(void)
{
    int n, m, min = 1000000, max = 1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m > max)
            max = m;
        if (m < min)
            min = m;
    }
    cout << max * min << endl;
}