#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<vector<long long>> timeTable(n, vector<long long>(2));
	long long max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> timeTable[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max < timeTable[i][1])
		{
			max = timeTable[i][1];
			//maxIndex = i;
		}
	}
	vector<long long> room(max + 1);
	for (int i = 0; i < max; i++)
	{
		room[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		room[timeTable[i][0]]++;
		room[timeTable[i][1]]--;
	}
	long long auditories = 0;
	for (int i = 0; i < max; i++)
	{
		if (room[i] > 0)
		{
			auditories += room[i];
		}
	}
	cout << auditories << endl;
	return 0;
}