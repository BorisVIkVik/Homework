#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 4, s = 27;
	vector<int> v1(n);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 8;
	v1[3] = 10;
	int coins = 0;
	for (int i = n-1; i > -1; i--)
	{
		coins += s / v1[i];
		s %= v1[i];
	}
	cout << coins << endl;
	return 0;	
}