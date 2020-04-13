#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//cin >> x1 >> y1;
	vector<vector<int>> dp(n, vector<int>(m));
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			dp[x][y] = 0;
		}
	}
	dp[0][0] = 1;
	if(n > 2)dp[2][1] = 1;
	if(m > 2)dp[1][2] = 1;
	for (int x = 2; x < n; x++)
	{
		for (int y = 2; y < m; y++)
		{
			dp[x][y] = dp[x - 1][y - 2] + dp[x - 2][y - 1];
			//dp[1][1] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n - 1][m - 1];
	return 0;
}