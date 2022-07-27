#include <iostream>


using namespace std;

struct node {
    int data;
    node* next;
};


void insert(node** head, int data)
{

    if (*head == nullptr)
    {
        node* n = new node();

        n->data = data;

        n->next = nullptr;

        *head = n;

        return;
    }

    node** temp = head;

    while((*temp)->next)
    {
        *temp = (*temp)->next;
    }

    (*temp)->next = new node();

    (*temp)->next->data = data;

    (*temp)->next->next = nullptr;

    return;
}


int main(int argc, const char* argv[])
{

    node* head = nullptr;

    insert(&head, 10);

    cout << head->data << endl;

    insert(&head, 20);

    cout << head->next->data << endl;

    return 0;
}