#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;

	node(int d): data(d), next(nullptr) {}
	~node(){}
};

void print(node* head)
{

	node* curr = head;

	while(curr)
	{
		cout << curr-> data << " ";
		curr = curr->next;
	}

	cout << endl;

}


int main(int argc, const char* argv[])
{

	node* curr = nullptr;
	node* head = new node(10); curr = head;
	curr->next = new node(20); curr = curr->next;
	curr->next = new node(30); curr = curr->next;
	curr->next = new node(40); curr = curr->next;

	print(head);


	return 0;
}