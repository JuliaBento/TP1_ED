#include <iostream>
//#include "stack.hpp"
//#include "matrizcoo.hpp"
#include "matrizEncadeada.hpp"

using namespace std;

int main()
{
    MatrizEncadeada matriz(3, 4);

    // Item 0: [2, 4, 0, 0]
    matriz.Set(0, 0, 2);
    matriz.Set(0, 1, 4);

    // Item 1: [1, 0, 3, 0]
    matriz.Set(1, 0, 1);
    matriz.Set(1, 2, 3);

    // Item 2: [0, 0, 0, 0]

    cout << "Soma do item 0: " << matriz.Soma(0) << endl;
    cout << "Soma do item 1: " << matriz.Soma(1) << endl;
    cout << "Soma do item 2: " << matriz.Soma(2) << endl;

    cout << "\nDesvio do item 0: " << matriz.Desvio(0) << endl;
    cout << "Desvio do item 1: " << matriz.Desvio(1) << endl;
    cout << "Desvio do item 2: " << matriz.Desvio(2) << endl;

    cout << "\nProduto entre item 0 e item 1: "
         << matriz.Produto(0, 1) << endl;

    cout << "Produto entre item 0 e item 0: "
         << matriz.Produto(0, 0) << endl;

    cout << "Produto entre item 0 e item 2: "
         << matriz.Produto(0, 2) << endl;

    return 0;
}


