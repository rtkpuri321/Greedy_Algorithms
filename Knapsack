#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll n;
	ll i, j;
	float m;
	cin >> n >> m;
	float p[n], w[n];
	for (i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	float pw[n];

	for (i = 0; i < n; i++)
	{
		pw[i] = p[i] / w[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << pw[i] << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (pw[i] < pw[j])
			{
				swap(p[i], p[j]);
				swap(w[i], w[j]);
				swap(pw[i], pw[j]);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	float prof = 0.0;
	for (i = 0; i < n; i++)
	{
		if (m > 0 && w[i] <= m)
		{
			m = m - w[i];
			prof += p[i];
		}
		else if (m > 0)
		{
			float ans = (m / w[i]);
			prof += ans * p[i];
			m = m - w[i];
		}
		else
			break;
	}
	cout << prof;
	return 0;
}
