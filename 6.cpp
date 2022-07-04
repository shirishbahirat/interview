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

node* insert(node* head, int index)
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

	head = insert(head, 10);

	head = insert(head, 20);

	cout << head->index << endl;



    return 0;
}
