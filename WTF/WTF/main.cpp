#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	int power = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n;j++)
		{
			if (v1[i] > v1[j])
			{
				power++;
			}
		}
	}
	cout << power << endl;
	return 0;
}