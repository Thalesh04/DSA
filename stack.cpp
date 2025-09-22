#include <bits/stdc++.h>

using namespace std;
// precedence of operators
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

// infix to postfix function
string infixToPostfix(string infix)
{
    string answer;
    stack<char> opStore;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        // if character is an operand
        if (isalnum(c))
        {
            answer += c;
        }
        // if character is '('
        else if (c == '(')
        {
            opStore.push(c);
        }
        // if character is ')'
        else if (c == ')')
        {
            while (!opStore.empty() && opStore.top() != '(')
            {
                answer += opStore.top();
                opStore.pop();
            }
            opStore.pop(); // pop the '('
        }
        // if character is an operator
        else
        {
            while (!opStore.empty() && precedence(opStore.top()) >= precedence(c))
            {
                answer += opStore.top();
                opStore.pop();
            }
            opStore.push(c);
        }
    }
    while (!opStore.empty())
    {
        answer += opStore.top();
        opStore.pop();
    }
    return answer;
}

int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Infix expression : " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression : " << postfix << endl;
}
