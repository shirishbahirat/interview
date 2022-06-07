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

node* inv_link_list(node* head)
{

	if (head == nullptr) return nullptr;

	node* prev = nullptr;
	node* curr = head;
	node* next = head->next;

	while(curr)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = curr->next;
	}

	head = prev;

	return head;

}


int main(int argc, const char* argv[])
{

	node* curr = nullptr;
	node* head = new node(10); curr = head;
	curr->next = new node(20); curr = curr->next;
	curr->next = new node(30); curr = curr->next;
	curr->next = new node(40); curr = curr->next;

	print(head);

	head = inv_link_list(head);

	print(head);

	return 0;
}