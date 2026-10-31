#include "stack.hpp"

using namespace std;

Node::Node()
{
    key = 0;
    next = NULL;
}

Node::Node(int k)
{
    key = k;
    next = NULL;
}

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    while (top != nullptr)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::checkIfNodeExist(Node *n)
{
    Node *temp = top;
    bool exist = false;
    while (temp != NULL)
    {
        if (temp->key == n->key)
        {
            exist = true;
            break;
        }
        temp = temp->next;
    }
    return exist;
}

bool Stack::push(Node *n)
{
    if (top == NULL)
    {
        top = n;
        return true;
    }
    else
    {
        Node *temp = top;
        top = n;
        n->next = temp;
        return true;
    }
}

Node *Stack::pop()
{
    Node *temp = NULL;
    if (isEmpty())
    {
        return temp;
    }
    else
    {
        temp = top;
        top = top->next;
    }
    return temp;
}

Node *Stack::peek()
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        return top;
    };
}

int Stack::count()
{
    int count = 0;
    Node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Stack::display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}
