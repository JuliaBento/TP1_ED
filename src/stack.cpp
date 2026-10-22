#include "stack.hpp"

using namespace std;

Node::Node()
{
    key = 0;
    data = 0;
    next = NULL;
}

Node::Node(int k, int d)
{
    key = k;
    data = d;
    next = NULL;
}

Stack::Stack()
{
    top = NULL;
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
    bool exist = checkIfNodeExist(n);

    if (top == NULL)
    {
        top = n;
        return true;
    }
    else if (exist)
    {
        cout << "Chave conflitante" << endl;
        return false;
    }
    else
    {
        Node *temp = top;
        top = n;
        n->next = temp;
        cout << "Item adicionado" << endl;
        return true;
    }
}

Node *Stack::pop()
{
    Node *temp = NULL;
    if (isEmpty())
    {
        cout << "Pilha vazia" << endl;
        return temp;
    }
    else
    {
        temp = top;
        top = top->next;
        cout << "Item removido" << endl;
    }
    return temp;
}

Node *Stack::peek()
{
    if (isEmpty())
    {
        cout << "Pilha vazia" << endl;
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
        cout << "(" << temp->key << "," << temp->data << ")" << endl;
        temp = temp->next;
    }
}
