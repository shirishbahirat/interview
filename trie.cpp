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
        if (curr->map.find(*str) == curr->map.end()) {
            curr->map[*str] = new trie(false);
        }
 
        curr = curr->map[*str];
 
        str++;
    }
 
    curr->isLeaf = true;


}

int main(int argc, const char* argv[])
{

   // trie: Peter, piper, picked, peck, pickled, and peppers

	return 0;
}
