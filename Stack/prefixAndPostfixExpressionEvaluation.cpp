#include <bits/stdc++.h>
using namespace std;
int prefixEvaluation(string prefixExpression)
{
    stack<int> s;
    for (int i = prefixExpression.length() - 1; i > 0; i--)
    {
        char c = prefixExpression[i];
        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
                s.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }
    return s.top();
}
int postfixEvaluation(string postfixExpression)
{
    stack<int> s;
    for (int i = 0; i < postfixExpression.length(); i++)
    {
        char c = postfixExpression[i];
        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else
        {
            char b = s.top();
            s.pop();
            char a = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
                s.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }
    return s.top();
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string infixExpression)
{
    string ans = "";
    stack<char> s;
    for (int i = 0; i < infixExpression.length(); i++)
    {
        char c = infixExpression[i];
        if (c >= '0' && c <= '9')
        {
            ans += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && precedence(c) < precedence(s.top()))
            {
                ans += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}
string infixToPrefix(string infixExpression)
{
    reverse(infixExpression.begin(), infixExpression.end());
    for (int i = 0; i < infixExpression.length(); i++)
    {
        if (infixExpression[i] == ')')
        {
            infixExpression[i] = '(';
        }
        else if (infixExpression[i] == '(')
        {
            infixExpression[i] = ')';
        }
    }
    infixExpression = infixToPostfix(infixExpression);
    reverse(infixExpression.begin(), infixExpression.end());
    return infixExpression;
}

int main()
{
    string infixExpression = "(1-2/3)*(4/5-6)";
    cout << infixToPostfix(infixExpression) << endl;
    cout << infixToPrefix(infixExpression) << endl;

    string prefixExpression = "-+7*45+20";
    cout << prefixEvaluation(prefixExpression) << endl;
    string postfixExpression = "46+2/5*7+";
    cout << postfixEvaluation(postfixExpression) << endl;

    return 0;
}