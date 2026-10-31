#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

using namespace std;

class Node {
    public:
        int key;
        Node* next;
    
        Node();
        Node(int k);
};

class Stack {
    public: 
        Node *top;

        Stack();
        ~Stack();
        bool isEmpty();//Verifies if the stack is empty
        bool checkIfNodeExist(Node* n);//Check if a especific node already exists
        bool push(Node* n);//Add a new node
        Node* pop();//Remove the top (last in) node
        Node* peek();//Returns the top node
        int count();//Counts the numbers of nodes 
        void display(); //Prints the stack    
};

#endif