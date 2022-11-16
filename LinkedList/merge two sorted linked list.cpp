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
        next = NULL;
    }
};
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
void insertAtStart(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}
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
                temp->next = node;
            }
            i++;
            temp = temp->next;
        }
    }
}
void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *nodeToDelete = NULL;
    if (temp && temp->data == key)
    {
        nodeToDelete = temp;
        head = temp->next;
    }
    else
    {
        while (temp)
        {
            if (temp->next && temp->next->data == key)
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
Node *merge(Node *head1, Node *head2)
{
    Node *temp;
    bool flag = 1;
    if ((head1->data <= head2->data))
    {
        temp = new Node(head1->data);
        head1 = head1->next;
    }
    else if ((head1->data > head2->data))
    {
        temp = new Node(head2->data);
        head2 = head2->next;
    }
    Node *head = temp;
    while (head1 && head2)
    {
        if ((head1->data <= head2->data))
        {
            cout << "head1" << endl;
            temp->next = new Node(head1->data);
            head1 = head1->next;
        }
        else if ((head1->data > head2->data))
        {
            cout << "head2" << endl;
            temp->next = new Node(head2->data);
            head2 = head2->next;
        }
        temp = temp->next;
    }
    while (head1)
    {
        temp->next = new Node(head1->data);
        head1 = head1->next;
        temp = temp->next;
    }
    while (head2)
    {
        temp->next = new Node(head2->data);
        head2 = head2->next;
        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head1 = new Node(2);
    insertAtTail(head1, 5);
    insertAtTail(head1, 8);
    insertAtTail(head1, 10);
    cout << "Linked List1: ";
    traverseLinkedList(head1);

    Node *head2 = new Node(1);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 12);
    insertAtTail(head2, 14);
    cout << "Linked List2: ";
    traverseLinkedList(head2);

    Node *head = merge(head1, head2);
    traverseLinkedList(head);

    return 0;
}