#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	int n;
	
	cin >> n;
	//vector<char> str(0);
	vector<vector<int>> arr(0, vector<int>(2));
	for (int j = 0; j < n; j++)
	{
		cin >> str;
		cin >> str;
		cin >> str;
		int num = 0;
		int koef = 1;
		for(int k = 0; k < str.size(); k++)
		{
			num *= koef;
			num += (int(str[k]) - '0');
			koef *= 10;
		}
		bool found = false;
		for (int i = 0; i < arr.size(); i++)
		{
			if (num == arr[i][0])
			{
				arr[i][1]++;
				found = true;
			}
		}
		if (found == false)
		{
			arr.push_back(vector<int>(2));
			arr[arr.size() - 1][0] = num;
			arr[arr.size() - 1][1] = 1;
		}
	}
	int max = 0;
	vector<int> index(1);
	for (int i = 0; i < arr.size(); i++)
	{
		if(max < arr[i][1])
		{
			if (index.size() != 1)
			{
				for (int t = 1; t < index.size(); t++)
				{
					index.pop_back();
				}
			}
			max = arr[i][1];
			index[0] = arr[i][0];
		}
		else if (max == arr[i][1])
		{
			index.push_back(arr[i][0]);
		}
	}
	for (int i = 0; i < index.size(); i++)
	{
		cout << index[i] << " ";
	}
	cout << endl;
	return 0;
}