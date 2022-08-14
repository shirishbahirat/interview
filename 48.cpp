#include <iostream>

using namespace std;

struct tree {
	char name;
	tree* left;
	tree* right;

	tree(char n):name(n), 
	left(nullptr), 
	right(nullptr) {}

	~tree(){}
};

void transverse(tree* head)
{
	tree* node = head;

	if (node == nullptr) return;

	cout << node->name << " ";

	transverse(node->left);
	transverse(node->right);

}


int main(int argc, char const* argv[])
{

	tree* head = new tree('a');

	head->left = new tree('b');
	head->right = new tree('c');


	head->left->left = new tree('d');
	head->left->right = new tree('e');


	head->right->left = new tree('f');
	head->right->right = new tree('g');

	transverse(head);
	cout << endl;

	return 0;
}