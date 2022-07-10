#include <iostream>
#include <cinttypes>

using namespace std;

class node {
	public : int data;
	node* both;
};

node* xor_both(node* x, node* y)
{
	return reinterpret_cast<node*>(
		reinterpret_cast<uintptr_t>(x)
		^ reinterpret_cast<uintptr_t>(y));
}

void insert(node** head_ref, int data)
{

	node* new_node = new node();
	new_node -> data = data;

	new_node -> both = *head_ref;

	if (*head_ref != NULL) {
		(*head_ref)
			-> both = xor_both(new_node, (*head_ref) -> both);
	}

	*head_ref = new_node;
}

void print_list(node* head)
{
	node* curr = head;
	node* prev = NULL;
	node* next;

	cout << "The nodes of Linked List are: \n";

	while (curr != NULL) {
		cout << curr -> data << " " << endl;
		next = xor_both(prev, curr -> both);

		prev = curr;
		curr = next;
	}
}

int main()
{
	node* head = NULL;
	insert(&head, 10);
	insert(&head, 100);
	insert(&head, 1000);
	insert(&head, 10000);

	print_list(head);

	return (0);
}

