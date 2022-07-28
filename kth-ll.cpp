#include <iostream>

using namespace std;

struct node {
    int data;

    node* next;

    node(int d): data(d), next(nullptr){}

    ~node(){}
};

void insert(node** head, int data)
{

    if (*head == nullptr)
    {
        node* n = new node(data);

        *head = n;

        return;
    }

    node** temp = head;

    node* h = *head;

    while((*temp)->next)
    {
        *temp = (*temp)->next;
    }

    (*temp)->next = new node(data);

    *head = h;

    return;
}


void print_last(node** head, int index)
{

    node* temp = *head;

    int count = 0;

    node* kth;

    while(temp->next)
    {
        temp = temp->next;

        count++;

        if (count > index)
        {
            kth = kth->next;
        }

        if (count == index)
        {
            kth = *head;
        }

    }

    cout << kth->next->data << endl;
}


int main(int argc, const char* argv[])
{

    node* head = nullptr;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    print_last(&head, 2);

   return 0;
}