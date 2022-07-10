#include <iostream>
#include <cinttypes>

using namespace std;

class node {
	public : int data;
	node* both;
};

node* Xor(node* x, node* y)
{
	return reinterpret_cast<node*>(
		reinterpret_cast<uintptr_t>(x)
		^ reinterpret_cast<uintptr_t>(y));
}

// Method 2
// Insert a node at the start of the Xored LinkedList and
// mark the newly inserted node as head
void insert(node** head_ref, int data)
{
	// Allocate memory for new node
	node* new_node = new node();
	new_node -> data = data;

	// Since new node is inserted at the
	// start , both of new node will always be
	// Xor of current head and NULL
	new_node -> both = *head_ref;

	// If linkedlist is not empty, then both of
	// present head node will be Xor of new node
	// and node next to current head */
	if (*head_ref != NULL) {
		// *(head_ref)->both is Xor of (NULL and next).
		// If we Xor Null with next we get next
		(*head_ref)
			-> both = Xor(new_node, (*head_ref) -> both);
	}

	// Change head
	*head_ref = new_node;
}

// Method 3
// It simply prints contents of doubly linked
// list in forward direction
void printList(node* head)
{
	node* curr = head;
	node* prev = NULL;
	node* next;

	cout << "The nodes of Linked List are: \n";

	// Till condition holds true
	while (curr != NULL) {
		// print current node
		cout << curr -> data << " " << endl;

		// get address of next node: curr->both is
		// next^prev, so curr->both^prev will be
		// next^prev^prev which is next
		next = Xor(prev, curr -> both);

		// update prev and curr for next iteration
		prev = curr;
		curr = next;
	}
}

// Method 4
// main driver method
int main()
{
	node* head = NULL;
	insert(&head, 10);
	insert(&head, 100);
	insert(&head, 1000);
	insert(&head, 10000);

	// Printing the created list
	printList(head);

	return (0);
}

