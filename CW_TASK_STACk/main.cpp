#include<iostream>
#include<vector>
using namespace std;
struct stacks
{
	int* arr;
	int index;
	int size;
	stacks(int len)
	{
		index = 0;
		arr = new int[len];
		size = len;
	}
	~stacks()
	{
		delete arr;
	}

	bool push(int a)
	{
		arr[index] = a;
		index++;
		if (index >= size)
		{
			return 1;
		}
		return 0;
	}
	int pop()
	{
		index--;
		if (index == -1)
		{
			index++;
			return-1;
		}
		int tmp = arr[index];
		return tmp;
	}
};
struct SetofStacks
{
	int indexS;
	int size;
	vector<stacks> SV;
	SetofStacks(int final)
	{
		indexS = 0;
		size = final;
		SV.resize(1);
		SV.pop_back();
		SV.push_back(size);
	}
	~SetofStacks();
	void pushToS(int b)
	{
		if (SV[indexS].push(b) == 1)
		{
			SV.push_back(size);
			indexS++;
		}
	}
	int popS()
	{
		int tmp;
		if (SV[indexS].pop() == -1)
		{
			indexS--;
			tmp = SV[indexS].pop();
		}
		return tmp;
	}
	int popAt(int s)
	{
		SV[s].pop();
	}
	
};
int main()
{
	return 0;
}