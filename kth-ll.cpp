#include <iostream>


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

		temp = n;
	}

	return;
}


int main(int argc, const char* argv[])
{

	node* head = nullptr;

	insert(&head, 10);



	return 0;
}