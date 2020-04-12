#include <iostream>
#include <vector>

using namespace std;
int solve(int x1, int y1)
{
	if (x1 == 1 && y1 == 1)
	{
		return 1;
	}
	if (x1 < 0 or y1 < 0)
	{
		return 0;
	}
	return (solve(x1 - 1, y1 - 2) + solve(x1 - 2, y1 - 1));
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << solve(n, m);
}