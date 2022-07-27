#include <iostream>


using namespace std;

struct node {
	int data;
	node* next;
};


void insert(node** head, int data)
{

	if (*head == nullptr)
	{
		node* n = new node();

		n->data = data;

		n->next = nullptr;

		*head = n;

		return;
	}

	node** temp = head;

	while((*temp)->next)
	{
		*temp = (*temp)->next;
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