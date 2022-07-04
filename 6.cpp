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

node* pre;
node* nxt;

node* insert(node* head, int index)
{
	if (head == nullptr)
	{
		pre = new node(index);

		head = pre;

		return head;
	}

	node* curr = head;

	while(curr->both)
	{
		uint64_t addr_prev =  reinterpret_cast<uint64_t>(pre);
		uint64_t add_curr =  reinterpret_cast<uint64_t>(curr->both);
		uint64_t addr_next = (addr_prev ^ add_curr);

		node* next =  reinterpret_cast<node*>(addr_next);

		curr = next;

		cout << curr->index << " ";
	}

	cout << endl;

	node* next = new node(index);

	next->both = pre;

	uint64_t addr_prev =  reinterpret_cast<uint64_t>(pre->both);
	uint64_t add_next =  reinterpret_cast<uint64_t>(curr);

	uint64_t addr_both = (addr_prev ^ add_next);

	pre->both = reinterpret_cast<node*>(addr_both);

	return head;
}

int main(int argc, char* argv[])
{

	node* head = nullptr;

	head = insert(head, 10);

	head = insert(head, 20);

	head = insert(head, 30);

	cout << head->index << endl;



    return 0;
}
