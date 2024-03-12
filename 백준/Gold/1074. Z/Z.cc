#include <iostream>
using namespace std;
int z(int r, int c, int size, int sum)
{
    if (size > 0)
    {
        if ((r < size) && (c < size))
        {
            return z(r, c, size / 2, sum);
        }
        else if ((r < size) && (c >= size))
        {
            return z(r, c - size, size / 2, sum + size * size * 1);
        }
        else if ((r >= size) && (c < size))
        {
            return z(r - size, c, size / 2, sum + size * size * 2);
        }
        else
        {
            return z(r - size, c - size, size / 2, sum + size * size * 3);
        }
    }
    return sum;
}

int main(void)
{
    int N, r, c;
    cin >> N >> r >> c;
    int size = 1;
    for (int i = 0; i < N; i++)
    {
        size *= 2;
    }
    cout << z(r, c, size / 2, 0);
}