#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct node {
	node* both;
	int index;

	node(int d):index(d){}
	~node(){}
};

node* insert(node* head, int index, node* &prev, node* &next)
{
	if (head == nullptr)
	{
		node* temp = new node(index);
	}

	head = temp;

	return head;
}

int main(int argc, char* argv[])
{

	node* head = nullptr;
	node* pev = 0x0;
	node* next = 0x0;


	head = insert(head, 10, prev, next);

	cout << (0x1 ^ 0x3) << endl;
	cout << (0x0 ^ 0x3) << endl;

    return 0;
}
