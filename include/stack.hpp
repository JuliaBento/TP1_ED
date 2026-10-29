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

        //Verifies if the stack is empty
        bool isEmpty();

        //Check if a especific node already exists
        bool checkIfNodeExist(Node* n);

        //Add a new node
        bool push(Node* n);

        //Remove the top (last in) node
        Node* pop();

        //Returns the top node
        Node* peek();

        //Counts the numbers of nodes 
        int count();

        //Prints the stack
        void display();     
};

#endif