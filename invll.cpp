#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;

	node(int d): data(d), next(nullptr) {}
};

int main(int argc, char* argv[])
{

	node* n = new node(10);

	node* head = n;

	n = new node(11);

	head->next = n;

	n = new node(12);

	head->next->next = n;

	node* temp = head;

	while(temp)
	{
		cout << temp->data << endl;

		temp = temp->next;
	}

	node* prev = nullptr;

	node* curr = head;

	node* next = head->next;

	while(curr->next)
	{
		curr->next = prev;

		prev = curr;

		curr = next;

		next = curr->next;
	}

	curr->next = prev;

	head = curr;

	temp = head;

	while(temp)
	{
		cout << "inv "<< temp->data << endl;
		temp = temp->next;
	}

	return 0;
}