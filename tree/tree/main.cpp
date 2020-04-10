#include <iostream>
#include <vector>

using namespace std;
struct node
{
public:
	node()
	{

	}
	~node()
	{

	}
	node* leftBranch, * rightBranch;
	int value;
};


void add(int data, node*& branch)
{
	if (!branch)
	{
		branch = new node;
		branch->value = data;
		branch->leftBranch = 0;
		branch->rightBranch = 0;
	}
	if (branch->value > data)
	{
		add(data, branch->leftBranch);
	}
	if (branch->value < data)
	{
		add(data, branch->rightBranch);
	}
}
int tabs = 0;
void printTree(node*& root)
{
	if (!root) return;
	tabs++;
	printTree(root->leftBranch);
	for (int i = 0; i < tabs; i++)
	{
		cout << "   ";
	}
	cout << root->value << endl;
	printTree(root->rightBranch);
	tabs--;
	return;
}
int main()
{
	node* Root = 0;
	int s[9] = { 0,1,3,2,4,-1,-2,-3,-4 };
	for (int i = 0; i < 9; i++)
	{
		add(s[i], Root);
	}
	printTree(Root);
	///vector<vector<int>> v1(0, vector<int>(0));
}