#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>

using namespace std;

class NoFila {
    public:
        int id_aventureiro;
        int id_item;
        NoFila* next;
};

class Fila {
    private: 
        NoFila *inicio;
        NoFila *fim;
        int tamanho;

        Fila();
        ~Fila();

    public:
        bool isEmpty();//Verifies if the stack is empty
        void push(int id_aventureiro, int id_item);//Add a new order
        NoFila* pop();//Remove the top (last in) node
        int count();//Counts the numbers of nodes 
};

#endif