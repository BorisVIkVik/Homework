#include <iostream>
#include <vector> 

using namespace std;

vector<int> arr(0);

void printD(int number)
{
	int sum41 = 0;
	for (int t = 0; t < number; t++)
	{
		if (sum41 + arr[t] == number)
		{
			cout << arr[t];
			cout << endl;
			return;
		}
		cout << arr[t] << "+";
		sum41 += arr[t];
	}
}

void decomp(int num, int first, int last, int sum)
{
	if (sum == num)
	{
		printD(num);
		return;
	}
	for (int i = last; first < num && i < num; i++)
	{
		arr[first] = i;
		if (sum + i > num)break;
		decomp(num, first + 1, i, sum + i);
	}
	if (first == 0)
	{
		cout << num;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	decomp(n, 0, 1, 0);
	return 0;
}