#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long  n;
	cin >> n;
	vector<long long> v1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	for (int i = n-1; i > -1; i--)
	{
		cout << v1[i] << endl;
	}
	return 0;

}