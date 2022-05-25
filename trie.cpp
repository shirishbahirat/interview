#include <iostream>
#include <map>

using namespace std;

struct trie
{
	bool is_leaf;

	map <char, trie*> nodes;

	trie(bool l): is_leaf(l){}

	~trie(){}
};



int main(int argc, const char* argv[])
{

   // trie: Peter, piper, picked, peck, pickled, and peppers

	return 0;
}
