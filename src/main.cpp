#include <iostream>
//#include "stack.hpp"
#include "matrizcoo.hpp"

using namespace std;

int main() {
    MatrizCOO matriz(5, 5);

    //Como vou implementar a LI em catálogo vai ser mais ou menos assim:

    int id_atributos[matriz.c]; //lembrar que para LA: matriz.l
    int valores_atributos[matriz.c];

    matriz.Set(0,0,1);
    matriz.Set(0,1,1);
    matriz.Set(0,2,1);
    matriz.Set(0,3,1);
    matriz.Set(0,4,1);

    matriz.Imprime();

    int total_atributos;

    total_atributos = matriz.itens_atributo(0, id_atributos, valores_atributos);

    cout << total_atributos << endl;

    for(int i = 0; i < total_atributos; i++){
        cout << "id_a: " << id_atributos[i] << " valor: "<< valores_atributos[i] << endl;
    }
    

//     Stack s1;

//     int comando, data, key;

//     Node* new_node = new Node();
    
//     cout << "Selecione o comando:" << endl;
//     cin >> comando;

//     switch (comando) {
//         case 0:
//             cout << "Sair" << endl;
//             break;  
        
//         case 1:
//             cout << "Incluir item:" << endl;
//             cin >> key;
//             cin >> data;
//             new_node->key = key;
//             new_node->data = data;
//             if (!s1.push(new_node)) {
//                 delete new_node;
//             }
//             break;

//         case 2:
//             cout << "Remover item:" << endl;
//             new_node = s1.pop();
//             delete new_node;
//             break;

//         case 3:
//             if(s1.isEmpty()) {
//                 cout << "Pilha vazia" << endl;
//             } else {
//                 cout << "Pilha não vazia" << endl;
//             }
//             break;
        
//         case 4:
//             if(s1.isEmpty()) {
//                 cout << "Pilha vazia" << endl;
//             } else {
//                 new_node = s1.peek();
//                 cout << "Item no topo: " << new_node->data << endl;
//             }
//             break;
        
//         case 5: {
//             int count = s1.count();
//             cout << count << endl;
//             break;
//         }
//         case 6:
//             cout << "Itens na pilha:" << endl;
//             s1.display();   
//             break;

//         case 7:
//             cout << "Sair" << endl;
//             break;
//     }
}


