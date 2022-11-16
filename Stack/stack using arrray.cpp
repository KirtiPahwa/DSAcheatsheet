#include <iostream>
using namespace std;
// Stack is LIFO  or FILO
// underflow-stack is empty
// overflow -stack is full
template <class T>
class Stack
{
    int index;

public:
    T *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new T(size);
        index = -1;
    }
    void push(T ele)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++index] = ele;
    }
    T top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[index];
    }
    bool isEmpty()
    {
        if (index == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    T isFull()
    {
        if (index == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        index--;
    }
    ~Stack()
    {
        delete arr;
    }
};

int main()
{
    Stack<int> s(10);
    cout << s.top() << endl;
    s.push(10);
    s.push(7);
    s.push(8);
    s.push(9);
    cout << s.top() << endl;
    s.pop();
    s.push(4);

    return 0;
}