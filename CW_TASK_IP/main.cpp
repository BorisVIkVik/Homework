#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int arr[4];
	
	int err = 0;
	string str;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	int k = 0, j = 1;
	getline(cin, str);
	if (str[str.size() - 1] == '.')
	{
		cout << "False" << endl;
		return 0;
	}
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] != '.')
		{
			err = 0;
			arr[k] += (str[i] - '0') * j;
			j *= 10;
		}
		else
		{
			j = 1;
			k++;
			err++;
			if (err > 1)
			{
				cout << "False" << endl;
				return 0;
			}
			if (k > 3)
			{
				cout << "False" << endl;
				return 0;
			}
		}

	}
	if (k != 3)
	{
		cout << "False" << endl;
		return 0;
	}
	if (arr[0] < 0 || arr[0] > 255)
	{
		cout << "False" << endl;
		return 0;
	}
	if (arr[1] < 0 || arr[1] > 255)
	{
		cout << "False" << endl;
		return 0;
	}
	if (arr[2] < 0 || arr[2] > 255)
	{
		cout << "False" << endl;
		return 0;
	}
	if (arr[3] < 0 || arr[3] > 255)
	{
		cout << "False" << endl;
		return 0;
	}
	cout << "True";
	return 0;
}