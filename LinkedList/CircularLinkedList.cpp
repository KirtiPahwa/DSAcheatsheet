#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = this;
    }
};
void traverseLinkedList(Node *head)
{

    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void insertAtStart(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        head->next = head;
        return;
    }
    node->next = head;
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = node;
    head = node;
}
void insertAtTail(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
}
bool search(Node *head, int key)
{
    Node *temp = head;
    if (temp->data == key)
    {
        cout << "Key found in the Linked List" << endl;
        return true;
    }
    temp = temp->next;
    while (temp != head)
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
void insertInBetween(Node *&head, int index, int data)
{
    Node *temp = head;
    if (index == 1)
    {
        insertAtStart(head, data);
    }
    else
    {
        Node *node = new Node(data);
        int i = 1;
        while (temp->next != head)
        {
            if (i == index - 1)
            {
                node->next = temp->next;
                temp->next = node;
                return;
            }
            i++;
            temp = temp->next;
        }
        if (index - 1 == i)
        {
            temp->next = node;
            node->next = head;
        }
    }
}
void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *nodeToDelete = NULL;
    if (temp && temp->data == key)
    {
        nodeToDelete = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete nodeToDelete;
    }
    else
    {
        while (temp->next != head)
        {
            if (temp->next->data == key)
            {
                nodeToDelete = temp->next;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    delete nodeToDelete;
}
int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertInBetween(head, 3, 7);
    deleteNode(head, 4);
    traverseLinkedList(head);

    return 0;
}