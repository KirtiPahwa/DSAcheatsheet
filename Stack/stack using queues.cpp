#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        this->N = 0;
    }
    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int elem = q1.front();
        q1.pop();
        N--;
        return elem;
    }
    int top()
    {
        if (empty())
        {
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return N;
    }
    bool empty()
    {
        if (q1.empty())
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    s.push(5);
    cout << s.top() << endl;

    return 0;
}