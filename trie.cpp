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

void insert(trie*& head, char* str)
{
	if (head == nullptr)
	{
		head = new trie(false);
	}

	trie* curr = head;

 	while (*str)
    {
        if (curr->nodes.find(*str) == curr->nodes.end()) {
            curr->nodes[*str] = new trie(false);
        }
 
        curr = curr->nodes[*str];
 
        str++;
    }
 
    curr->is_leaf = true;


}

int main(int argc, const char* argv[])
{

   // trie: Peter, piper, picked, peck, pickled, and peppers

	return 0;
}
