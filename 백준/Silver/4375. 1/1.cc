#include <iostream>

using namespace std;

int main(void)
{
    while (1)
    {
        string s;
        int n, m, count;

        getline(cin, s);
        if (s.empty())
            break;
        n = stoi(s);
        m = 1;
        count = 1;
        while (m % n != 0)
        {
            count++;
            m = (m * 10 + 1) % n;
        }
        cout << count << endl;
    }
}