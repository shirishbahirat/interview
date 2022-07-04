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

node* prev = nullptr;
node* next = nullptr;

node* insert(node* head, int index, node* prev)
{
	if (head == nullptr)
	{
		prev = new node(index);
		head = prev;
	}


	return head;
}

int main(int argc, char* argv[])
{

	node* head = nullptr;
	node* prev = 0x0;
	node* next = 0x0;

	head = insert(head, 10, prev);

	head = insert(head, 20, prev);

	cout << head->index << endl;



    return 0;
}
