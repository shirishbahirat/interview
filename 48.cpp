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


int main(int argc, char const* argv[])
{

	tree* head = new tree('a');

	return 0;
}