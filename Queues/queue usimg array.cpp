#include <iostream>
using namespace std;
class Queue
{
    int size;
    int front, rear;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int(size);
        front = -1;
        rear = -1;
    }
    void enqueue(int ele)
    {
        if (is_full())
        {
            cout << "Overflow" << endl;
        }
        if (front == -1)
        {
            front++;
        }
        arr[++rear] = ele;
    }
    void dequeue()
    {
        if (is_empty())
        {
            cout << "Underflow" << endl;
        }
        front++;
    }
    int peek()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        return ans;
    }
    bool is_full()
    {
        if (size == rear + 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool is_empty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Queue s(10);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);

    cout << s.peek() << endl;
    s.dequeue();
    s.dequeue();
    s.dequeue();
    cout << s.peek() << endl;
    return 0;
}