#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void insertAtTail(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}
void insertAtStart(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}
void traverseLinkedList(Node *head)
{

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            cout << "Key found in the Linked List" << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Key not found in the Linked List" << endl;
    return false;
}
void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *nodeToDelete = NULL;
    if (temp && temp->data == key)
    {
        nodeToDelete = temp;
        head = temp->next;
        temp->next->prev = NULL;
    }
    else
    {
        while (temp)
        {
            if (temp->next && temp->next->data == key)
            {
                nodeToDelete = temp->next;
                temp->next = temp->next->next;
                temp->next->next->prev = temp;
                break;
            }
            temp = temp->next;
        }
    }
    delete nodeToDelete;
}
void insertInBetween(Node *&head, int index, int data)
{
    Node *temp = head;
    int i = 1;
    if (index == 1)
    {
        insertAtStart(head, data);
    }
    else
    {
        Node *node = new Node(data);

        while (temp)
        {
            if (i == index - 1)
            {
                node->next = temp->next;
                temp->next->prev = node;
                node->prev = temp;
                temp->next = node;
            }
            i++;
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtStart(head, 0);
    search(head, 3);
    search(head, 9);
    insertInBetween(head, 4, 8);
    deleteNode(head, 0);

    traverseLinkedList(head);

    return 0;
}