#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct node {

    node* both;

    node* next;

    node* prev;

    int index;

    node(int d):index(d), 
                both(nullptr),
                
                next(nullptr),
                prev(nullptr){}
    ~node(){}
};

node* pre = nullptr;

node* head = nullptr;

node* next = nullptr;

node* xor_both(node* pre, node* next)
{

    uint64_t addr_prev =  reinterpret_cast<uint64_t>(pre->both);

    uint64_t add_next =  reinterpret_cast<uint64_t>(next);

    uint64_t addr_both = (addr_prev ^ add_next);

    return reinterpret_cast<node*>(addr_both);

}

void insert(int index)
{
    if (head == nullptr)
    {
        pre = new node(index);

        head = pre;

        return;
    }

    node* next = new node(index);

    pre->both = xor_both(pre, next);

    pre->next = next;

    next->prev = pre;

    next->both = pre;

    pre = next;

    return;
}

int main(int argc, char* argv[])
{

    insert(10);

    cout << head->index << endl;

    insert(20);

    cout << head->next->index << endl;

    cout << "rev " << head->next->prev->index << endl;

    insert(30);

    cout << head->next->next->index << endl;

    cout << "rev " << head->next->next->prev->index << endl;

    insert(40);

    cout << head->next->next->next->index << endl;

    cout << "rev " << head->next->next->next->prev->index << endl;

    return 0;
}
