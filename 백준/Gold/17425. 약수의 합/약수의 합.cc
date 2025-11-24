#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    long long sum[1000001] = {};

    for (int i = 1; i < 1000001; i++)
    {
        for (int j = i; j < 1000001; j += i)
        {
            sum[j] += i;
        }
        sum[i] += sum[i - 1];
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << sum[m] << '\n';
    }
}