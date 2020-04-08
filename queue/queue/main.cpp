#include <iostream>

#define SIZE 6

using namespace std;
struct queue
{
	private:
		
		int* arr;//Создаём динамический массив
		bool empty()
		{
			if (pointerBot == pointerTop)
				return 1;
			else
				return 0;
		}
	public:
		int pointerTop, pointerBot;
		bool start;
		bool end;
		bool f;
		queue(int size = SIZE)
		{
			start = 0;
			f = 0;
			end = 0;
			arr = new int[size]; 
			pointerTop = -1;//присваеваем индексу добавляемого элемента значение 
			pointerBot = 0;
		}
		~queue()
		{
			delete[] arr;
		}
		bool push(int x)
		{
			if (pointerTop == SIZE-1)
			{
				pointerTop = -1;
				end = 1;
				//cout <<"gay"<< end << endl;
			}
			if ((pointerTop+1 == pointerBot) && start != 0 && f != 1)
			{
				
				return 0;
			}
			else 
			{
				arr[++pointerTop] = x;
				start = 1;
				f = 0;
			}
		}
		/*int pop()
		{
			if (pointerBot != SIZE - 1)
			{
				return arr[++pointerBot];
			}
			else
			{
				pointerBot = -1;
			}
		}*/
		int pop()
		{
			
			//cout <<"E "<< end <<" B "<<pointerBot << "T" << pointerTop << endl;
			if ((pointerBot-1 == pointerTop) && end != 1)
			{
				f = 1;
				//cout << "YAY";
				return 0;
			}
			else
			{
				if ((pointerBot == pointerTop) && end != 1)
				{
					f = 1;
					//return 0;
				}
				if (pointerBot+1 == SIZE)
				{
					int tmp = arr[pointerBot];
					pointerBot = 0;
					end = 0;
					if ((pointerBot-1 == pointerTop))
					{
						f = 1;
						//cout << "OMG";
						//return 0;
					}
					return tmp;
				}
				return arr[pointerBot++];
			}
			//if (pointerBot == SIZE)
			//{
			//	pointerBot = 0;
			//	end = 0;
			//}
		}
		int front()
		{
			if (!empty())
			{
				if (pointerTop != -1)
					return arr[pointerTop];
				else
				{
					return arr[SIZE - 1];
				}
			}
			else
			{
				return 0;
			}
		}
		int back()
		{
			if (!empty())
			{
				if (pointerBot != -1)
				{
					return arr[pointerBot];
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
};
int main()
{
	queue bruh;
	bruh.push(1);
	bruh.push(2);
	bruh.push(3);
	bruh.push(4);
	//cout << bruh.pointerTop << endl;
	bruh.push(5);
	bruh.push(6);
	bruh.push(7);
	cout << bruh.front() << endl;
	cout << bruh.back() << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	
	//cout << bruh.pointerBot << endl;
	//cout << bruh.pointerTop << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << endl;
	bruh.push(1);
	bruh.push(2);
	bruh.push(3);
	bruh.push(4);
	//cout << bruh.pointerTop << endl;
	bruh.push(5);
	bruh.push(6);
	//cout << bruh.pointerTop << endl;
	bruh.push(7);
	//cout << bruh.pointerTop << endl;
	cout << bruh.front() << endl;
	cout << bruh.back() << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << endl;
	//cout << bruh.pointerBot << endl;
	//cout << bruh.pointerTop << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;
	cout << bruh.pop() << endl;
	//cout << bruh.pointerBot << endl;

	return 0;
}