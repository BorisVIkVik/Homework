#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v1(100001);
	int value[6] = { 10, 20, 50, 100, 200, 500 };
	int n;
	for (int i = 0; i < 6; i++)
	{
		v1[value[i]] = 1;
	}
	for (int i = 10; i < 100001; i += 10)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i + value[j] < 100001 && v1[i + value[j]] == 0)
			{
				v1[i + value[j]] = v1[i] + 1;
			}
		}
	}
	cin >> n;
	if (v1[n] == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << v1[n] << endl;
	}
	return 0;
}