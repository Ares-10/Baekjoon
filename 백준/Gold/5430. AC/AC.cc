#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void R(int *a, const int first, int &size)
{
	int tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = tmp;
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int k; k < T; k++)
	{
		string p, a;
		cin >> p;
		int n, f = 0;
		cin >> n;
		int x[100001] = {0};
		cin >> a;
		int idx = 0;
		int tdx = 0;
		string tm = "";
		while (a[tdx] != ']')
		{
			if (a[tdx] == '[')
				tdx++;
			else if (a[tdx] == ',')
			{
				x[idx] = stoi(tm);
				idx++;
				tdx++;
				tm = "";
			}
			else
			{
				tm += a[tdx];
				tdx++;
			}
		}
		if (tm != "")
		{
			x[idx] = stoi(tm);
			idx++;
		}
		bool b = true;
		for (int i = 0; p[i] != '\0'; i++)
		{
			if (p[i] == 'R')
			{
				if (b == true)
					b = false;
				else
					b = true;
			}

			else if (n <= 0)
			{
				n = -1;
				break;
			}
			else if (b)
				f++;
			else
				n--;
		}

		if (n<f)
		{
			cout << "error\n";
			continue;
		}
		if (b)
		{
			cout << '[';
			if (n != f)
			{
				cout << x[f];
				for (int i = f + 1; i < n; i++)
				{
					cout << ',' << x[i];
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << '[';
			if (n != f)
			{
				cout << x[n - 1];
				for (int i = n - 2; i >= f; i--)
				{
					cout << ',' << x[i];
				}
			}
			cout << "]\n";
		}
	}
}