#include <iostream>
#include <map>

using namespace std;

struct trie{
	bool is_leaf;

	map <char, trie*> nodes;

	trie():is_leaf(false){}
	~trie() {}
};

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

void insert(trie*& head, char* name)
{

	if (head == nullptr)
	{
		head = new trie();
	}

	trie* curr = head;

	while(*name)
	{
		
		if (curr->nodes.find(*name) == curr->nodes.end())
		{
			curr->nodes[*name] = new trie();
		}

		curr = curr->nodes[*name];

		cout << *name;
		name++;
	}
	cout << endl;

	curr->is_leaf = true;

	return;
}

bool search(trie* head, char* str)
{
	if (head == nullptr) return false;

	trie* curr = head;

	while(*str)
	{

		curr = curr->nodes[*str];

		if (curr == nullptr) return false;

		str++;
	}

	return curr->is_leaf;

}

int main(int argc, const char* argv[])
{
	trie* head = nullptr;

	insert(head, (char*)"hello");
	cout << search(head, (char*)"hello") << endl; 

	insert(head, (char*)"helloworld");
	cout << search(head, (char*)"helloworld") << endl; 


	return 0;
}