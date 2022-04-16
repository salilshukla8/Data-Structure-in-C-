#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *previous;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        previous = NULL;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{

public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    // 1.Check if node exists using key value

    Node *checkIfNodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. Append a node to the list

    void appendNode(Node *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node Already Exists with key value : " << n->key << ". Append a node with different key value." << endl;
        }

        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as Head Node" << endl;
            }

            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    // 3. Prepend a node to the list

    void prependNode(Node *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node Already Exists with key value : " << n->key << ". Append a node with different key value." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Prepended as head node" << endl;
            }
            else
            {
                head->previous = n;
                n->next = head;

                head = n;
                cout << "Node Prepended" << endl;
            }
        }
    }

    // 4. Inserting a node after a particular key value

    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "There is no node with key value : " << k << ". Try entering different key value" << endl;
        }
        else
        {
            Node *nextNode = ptr->next;
            if (nextNode == NULL)
            {
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Inserted at the END" << endl;
            }
            else
            {
                n->next = nextNode;
                nextNode->previous = n;
                ptr->next = n;
                n->previous = ptr;

                cout << "Node Inserted in BETWEEN" << endl;
            }
        }
    }

    // 5. Delete a node by unique key

    void deleteNodeByKey(int k)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value : " << k << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Unlinked with key value : " << k << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->previous;

                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node Deleted at the END" << endl;
                }

                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Node Deleted in Between" << endl;
                }
            }
        }
    }

    // 6. Update node by key

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "Node does not exist with key value : " << k << endl;
        }
    }

    // 7. Printing the nodes

    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Doubly Linked List" << endl;
        }

        else
        {
            cout << "Doubly Linked List Values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") <--> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList obj;
    int key1, k1, data1;
    int option;
    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to Exit. " << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;

        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Append Node Operation. \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.appendNode(n1);
            break;

        case 2:
            cout << "Perepend Node Operation. \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation. \nEnter key of the existing Node after which you want to insert this New Node" << endl;
            cin >> k1;
            cout << "Enter key & data of the new Node first :" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Delete Node By Key Operation.\nEnter key of the Node to be deleted" << endl;
            cin >> k1;

            obj.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "Update Node By Key Operation. \nEnter key & new data of the Node to be updated" << endl;
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
            cout << "Enter Proper Option Number" << endl;
        }

    } while (option != 0);

    return 0;
}