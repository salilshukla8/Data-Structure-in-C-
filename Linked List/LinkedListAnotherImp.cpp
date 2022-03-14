#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;

    if(head==NULL)
    {
        head=n;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}

void deleteAtHead(node* &head)
{
    node* temp=head;
    head=head->next;
    delete temp;
}


void deletion(node* &head,int val)
{
    if(head==NULL)
    {
        cout<<"Linked List is EMPTY"<<endl;
        return;
    }

    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }

    node* temp=head;
    while (temp->next->data!=val)
    {
        temp=temp->next;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}


bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}


void display(node* &head)
{
    node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    deletion(head,2);
    display(head);
    return 0;
}