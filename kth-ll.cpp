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

    node* h = *head;

    while((*temp)->next)
    {
        *temp = (*temp)->next;
    }

    (*temp)->next = new node();

    (*temp)->next->data = data;

    (*temp)->next->next = nullptr;

    *head = h;

    return;
}


void print_last(node** head, int index)
{

    node** temp = head;

    node* h = *head;

    int count = 0;

    node** kth = nullptr;

    while((*temp)->next)
    {
        *temp = (*temp)->next;
        count++;

        if (kth)
        {
            *kth = (*kth)->next;
        }

        if (count == index)
        {
            *kth = *head;
        }
    }

    cout << (*kth)->data << endl;

    *head = h;
}


int main(int argc, const char* argv[])
{

    node* head = nullptr;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    print_last(&head, 3);

   return 0;
}