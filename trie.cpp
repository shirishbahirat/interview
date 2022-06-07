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


bool have_children(trie const* curr)
{
 
    for (auto it: curr->nodes)
    {
        if (it.second != nullptr) {
            return true;
        }
    }
 
    return false;
}

bool deletion(trie*& curr, char* str)
{

    if (curr == nullptr) {
        return false;
    }
 
    if (*str)
    {

        if (curr != nullptr && curr->nodes.find(*str) != curr->nodes.end() &&
            deletion(curr->nodes[*str], str + 1) && curr->is_leaf == false)
        {
            if (!have_children(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    if (*str == '\0' && curr->is_leaf)
    {
        if (!have_children(curr))
        {
            delete curr;
            curr = nullptr;
            return true;
        }
        else {
            curr->is_leaf = false;
            return false;
        }
    }
 
    return false;
}

bool search(trie* head, char* str)
{

    if (head == nullptr) {
        return false;
    }
 
    trie* curr = head;

    while (*str)
    {
        curr = curr->nodes[*str];
 
        if (curr == nullptr) {
            return false;
        }
 
        str++;
    }
 
    return curr->is_leaf;
}

int main(int argc, const char* argv[])
{

   // trie: Peter, piper, picked, peck, pickled, and peppers

	trie* head = nullptr;
 
   	insert(head, (char*)"hello");
   	cout << search(head, (char*)"hello") << " "; 
 
   	insert(head, (char*)"helloworld");
    cout << search(head, (char*)"helloworld") << " ";
 
    cout << search(head, (char*)"helll") << " "; 
 
    insert(head, (char*)"hell");
    cout << search(head, (char*)"hell") << " "; 
 
	return 0;
}
