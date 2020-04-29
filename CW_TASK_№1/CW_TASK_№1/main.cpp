#include <iostream>
#include <vector> 

using namespace std;

vector<int> arr(0);

void printD(int number)//function that prints array that is a decompiled number
{
	int sum41 = 0;
	for (int t = 0; t < number; t++)
	{
		if (sum41 + arr[t] == number) // if the our summary plus next element of array will give our number, we print it and stop the printing of array
		{
			cout << arr[t];
			cout << endl;
			return;
		}
		cout << arr[t] << "+";
		sum41 += arr[t];
	}
}
/*function that decompiles our number
Logic: It uses recursion to change next element of array. It enumirates element, than check that our summary isn't bigger then our number, if it isn't then we go to next element and check 
our summary. If it equal then we print it with function printD and then go back to previous element. If it not equal to our number we start enumiration of next element and the operation 
repeats. If we enumirated all the options of current element than we go back to previous element. If we went to first element and enumirated it then we print our number that is our last 
decomposition. To escape the repeating of the number we start the enumiration of the next element with the previous element.
arg: num - is our number, element - is the number of our current element, last - is previous element, sum - is our current summary.
*/
void decomp(int num, int element, int last, int sum)
{
	if (sum == num)//The end of recursion
	{
		printD(num);//printing the line
		return;
	}
	for (int i = last; i < num; i++) // it goes until it check all the options
	{
		arr[element] = i;// changing the current element with current option
		if (sum + i > num)break; //check that our summary isn't bigger then our number.
		decomp(num, element + 1, i, sum + i); // recursion
	}
	if (element == 0)//if it a first element and the enumiration ended then it means that we checked all the options
	{
		cout << num;//so we print our number that is our final decompilation
	}
	return;//Second end of recursion
}

int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	decomp(n, 0, 1, 0);
	return 0;
}