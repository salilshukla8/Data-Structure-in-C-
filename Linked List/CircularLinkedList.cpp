#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    // 1. Check if node exists using key value
    Node *checkIfNodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }

        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }

    // 2. Append a node to the List

    void appendNode(Node *new_node)
    {
        if (checkIfNodeExists(new_node->key) != NULL)
        {
            cout << "Node Aleardy exists with key value : " << new_node->key << " .Append another node with different key value" << endl;
        }

        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node Appended at first Head Position" << endl;
            }

            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "Node Appended" << endl;
            }
        }
    }

    // 3. Prepend Node - Attach a node to the start

    void prependNode(Node *new_node)
    {
        if (checkIfNodeExists(new_node->key) != NULL)
        {
            cout << "Node Aleardy exists with key value : " << new_node->key << " .Append another node with different key value" << endl;
        }

        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node Prepended at first Head Position" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;

                new_node->next = head;
                head = new_node;
                cout << "Node Prepended" << endl;
            }
        }
    }

    // 4. Insert a New Node after a particular node in the List

    void insertNodeAfter(int k, Node *new_node)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with key value : " << k << endl;
        }

        else
        {
            if (checkIfNodeExists(new_node->key) != NULL)
            {
                cout << "Node Aleardy exists with key value : " << new_node->key << " .Append another node with different key value" << endl;
            }

            else
            {
                if (ptr->next == head)
                {
                    new_node->next = head;
                    ptr->next = new_node;
                    cout << "Node inserted at the END" << endl;
                }

                else
                {
                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    cout << "Node Inserted In BETWEEN" << endl;
                }
            }
        }
    }

    // 5. Delete a node by using unique key

    void deleteNodeByKey(int k)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with key value :" << k << endl;
        }

        else
        {
            if (ptr == head)
            {
                if (ptr->next == head)
                {
                    head = NULL;
                    cout << "Head Node Unlinked... List Empty" << endl;
                }

                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node UNLINKED with key value :" << k << endl;
                }
            }

            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;

                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        currentptr = currentptr->next;
                        prevptr = prevptr->next;
                    }
                }

                prevptr->next = temp->next;
                cout << "Node UNLINKED with key value :" << k << endl;
            }
        }
    }

    // 6. Update Node By Key value

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr== NULL)
        {
            cout << "No Node exists with key value :" << k << endl;
        }
        else
        {
            ptr->data = d;
            cout << "Node Data Updated Successfully" << endl;
        }
    }

    // 7. Printing the Circular Linked List

    void printList()
    {
        if (head == NULL)
        {
            cout << "Linked List is EMPTY" << endl;
        }
        else
        {
            cout << endl
                 << "Head Address :" << head << endl;
            cout << "Circular Linked List Values :" << endl;
            Node *ptr = head;
            do
            {
                cout << "(" << ptr->key << "," << ptr->data <<","<<ptr->next<<") -->";
                ptr = ptr->next;
            } while (ptr != head);
        }
    }
};

int main()
{
    CircularLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to Exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. printList()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;
        Node *n1 = new Node();
        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Append Node Operation \nEnter key and data of new node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key and data of the new node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of the existing node after which you want to insert new node :" << endl;
            cin >> k1;

            cout << "Enter Key and Data of the New Node First :" << endl;

            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Delete Node Operation \nEnter key of the node which you want to delete :" << endl;
            cin >> k1;

            obj.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "Update Node Operation \nEnter key and new data to be Updated :" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);
            break;

        case 6:
            obj.printList();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter proper option number" << endl;
        }
    } while (option != 0);

    return 0;
}