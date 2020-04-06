#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;
struct student
{
	public:
		string name;
		string lastName;
		float grade;
		student()
		{

		}
		~student()
		{

		}
};
bool cmp(student first, student second)
{
	return first.grade < second.grade;
}
int main()
{
	long long n;
	
	cin >> n;

	vector<student> students(n);
	for (int iFirst = 0; iFirst < n; iFirst++)
	{
		float averageMark = 0;
		cin >> students[iFirst].name;
		cin >> students[iFirst].lastName;
		int8_t tmp;
		cin >> tmp;
		averageMark += tmp;
		cin >> tmp;
		averageMark += tmp;
		cin >> tmp;
		averageMark += tmp;
		averageMark /= 3;
		students[iFirst].grade = averageMark;
	}
	sort(students.begin(), students.end(), cmp);
	for (int i = n-1; i > -1; i--)
	{
		cout << students[i].name << " " << students[i].lastName << endl;
	}
	return 0;
}