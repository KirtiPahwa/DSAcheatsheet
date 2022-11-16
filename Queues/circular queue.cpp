#include <iostream>
using namespace std;

class Queue
{
public:
    int front, rear;
    int size;
    int *arr;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == (rear + 1) % size)
        {
            return 1;
        }
        return 0;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void enqueue(int ele)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        if (front == -1)
        {
            front = 0;
            arr[rear] = ele;
        }
        else
        {
            arr[rear] = ele;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return;
        }
        front = (front + 1) % size;
    }
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(5);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.enqueue(3);

    return 0;
}
