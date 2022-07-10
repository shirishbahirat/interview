#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct node {

    node* both;

    int index;

    node(int d):index(d), 
                both(nullptr) {}

    ~node(){}
};

node* pre = nullptr;

node* head = nullptr;

node* next = nullptr;

node* xor_both(node* pre, node* next)
{

    if (pre == nullptr) return next;

    if (next == nullptr) return pre;

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

    pre->both = xor_both(pre->both, curr);

    pre = curr;

    return;
}

void print(node* head)
{

    if (head == nullptr) return;

    node* temp = head;
    node* prev = nullptr;
    node* ptemp = nullptr;

    while(temp)
    {
        cout << "print " <<temp->index << " ";

        if (temp->both == prev) break;
 
        cout << temp << " ";

        cout << xor_both(prev, temp->both) << endl;

        ptemp = temp;

        temp = xor_both(prev, temp->both);

        prev = ptemp;

    }

    cout << "done" << endl;

    return;
}

int main(int argc, char* argv[])
{

    insert(10);

    insert(20);

    insert(30);

    insert(40);

    insert(50);

    print(head);

    return 0;
}
