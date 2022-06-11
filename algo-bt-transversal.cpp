#include <iostream>

using namespace std;

struct tree {
	int data;
	tree* left;
	tree* right;

	tree(int d): data(d), left(nullptr), right(nullptr) {}
	~tree() {}
};


void transverse(tree* head)
{
	if (head == nullptr) return;

	transverse(head->left);

	transverse(head->right);

	cout << head->data << endl;

}


int main(int argc, const char* argv[])
{

	tree* head = new tree(10);

	head->left = new tree(9);
	head->right = new tree(14);


	head->left->left = new tree(7);
	head->left->right = new tree(4);

	head->right->left = new tree(11);
	head->right->right = new tree(12);


	transverse(head);


	return 0;
}