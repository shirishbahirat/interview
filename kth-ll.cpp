#include <iostream>


using namespace std;

struct node {
	int data;
	node* next;
};


void insert(node** head, int data)
{

	node* temp = *head;

	if (temp == nullptr)
	{
		node* n = new node();

		n->data = data;

		n->next = nullptr;

		*head = n;
	}

	return;
}


int main(int argc, const char* argv[])
{

	node* head = nullptr;

	insert(&head, 10);

	cout << head->data << endl;

	return 0;
}