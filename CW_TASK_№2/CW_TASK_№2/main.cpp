#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> v1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	int cur = n - 1;
	int coins = 0;
	while (s > 0)
	{
		if (s >= v1[cur])
		{
			coins++;
			s -= v1[cur];
		}
		else
		{
			cur--;
		}
	}
	cout << coins << endl;
	return 0;
}