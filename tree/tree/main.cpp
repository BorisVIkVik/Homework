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
node*& deleteNode(node*& root, int value_)
{
	if (!root)return root;
	if (value_ == root->value)
	{
		node* tmp;
		if (root->rightBranch == NULL)
		{
			tmp = root->leftBranch;
		}
		else
		{
			node* ptr = root->rightBranch;
			if (ptr->leftBranch == NULL) {
				ptr->leftBranch = root->leftBranch;
				tmp = ptr;
			}
			else {

				node* pmin = ptr->leftBranch;
				while (pmin->leftBranch != NULL) {
					ptr = pmin;
					pmin = ptr->leftBranch;
				}
				ptr->leftBranch = pmin->rightBranch;
				pmin->leftBranch = root->leftBranch;
				pmin->rightBranch = root->rightBranch;
				tmp = pmin;
			}
		}
		delete root;
		return tmp;
	}
	else if (value_ < root->value)
	{
		root->leftBranch = deleteNode(root->leftBranch, value_);
	}
	else if (value_ > root->value)
	{
		root->rightBranch = deleteNode(root->rightBranch, value_);
	}
	return root;
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
	deleteNode(Root, -3);
	printTree(Root);
	///vector<vector<int>> v1(0, vector<int>(0));
}