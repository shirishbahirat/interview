#include <iostream>
#include <map>

struct trie
{
	bool is_leaf;

	map <char, trie*> nodes;

	trie(bool l): is_leaf(l){}

	~trie(){}
};




using namespace std;

int main(int argc, const char* argv[])
{

   // trie: Peter, piper, picked, peck, pickled, and peppers

	return 0;
}
