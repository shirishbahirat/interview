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

    if (pre == nullptr) return next;

    uint64_t addr_prev =  reinterpret_cast<uint64_t>(pre->both);

    uint64_t add_next =  reinterpret_cast<uint64_t>(next);

    uint64_t addr_both = (addr_prev ^ add_next);

    return reinterpret_cast<node*>(addr_both);

}

void insert(int index)
{
    
    node* curr = new node(index);

    curr->both = pre;

    if (head == nullptr)
    {
        head = curr;
        
        pre = curr;

        return;
    }

    cout << "insert " << pre->index << " " << curr->index << endl;


    pre->both = xor_both(pre->both, curr);

    pre = curr;

    return;
}

void print(node* head)
{

    node* prev = nullptr;

    node* curr = head;

    cout << head->index << endl;

    node* next = curr->both;

    
    while(next != pre)
    {

        next = xor_both(curr->both, prev);

        cout << next->index << endl;

        prev = curr;

    }

    return;
}

int main(int argc, char* argv[])
{

    insert(10);

    insert(20);

    insert(30);

    insert(40);

    print(head);

    return 0;
}
