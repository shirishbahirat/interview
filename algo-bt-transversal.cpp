#include <iostream>
#include <queue>
#include <stack>

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

	tree* node = head;

	transverse(node);

	node = head;

	queue <tree*> bfs;

	bfs.push(node);

	cout << "bfs ";

	while (!bfs.empty())
	{
		node = bfs.front();
		cout << node->data << " ";
		bfs.pop();

		if (node->left) bfs.push(node->left);
		if (node->right) bfs.push(node->right);

	}

	cout << endl;


	node = head;

	stack <tree*> dfs;

	dfs.push(node);

	cout << "dfs ";

	while (!dfs.empty())
	{
		node = dfs.top();
		cout << node->data << " ";
		dfs.pop();

		if (node->right) dfs.push(node->right);
		if (node->left) dfs.push(node->left);

	}

	cout << endl;


	return 0;
}