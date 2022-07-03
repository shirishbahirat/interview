#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct node {
	node* both;
	int index;
};

//both = prev ^ next


int main(int argc, char* argv[])
{

	cout << (1 ^ 3) << endl;
	cout << (2 ^ 3) << endl;

    return 0;
}
