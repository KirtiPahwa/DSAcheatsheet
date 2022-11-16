#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int ele)
    {
        s1.push(ele);
    }
    int pop()
    {
        if (empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int deleted = s2.top();
        s2.pop();
        return deleted;
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
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
    Queue q;
    q.push(1);
    q.push(2);
    cout << q.pop();
    return 0;
}