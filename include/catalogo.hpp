#ifndef CATALOGO_HPP
#define CATALOGO_HPP
#include "matrizcoo.hpp"
#include "matrizEncadeada.hpp"
#include <string>

class Catalogo 
{
    public:
        Catalogo();
        
        void E_modo(char modo);

        void limpar_matriz();

        void M_modificador(int id_item, int id_atributo, int valor);

        int LI_consulta(int id_atributo, int* itens, int* modificadores);

        int LA_consulta(int id_item, int* atributos, int* modificadores);

        //function used to suport build aventureiro sets the vector range
        int quantidade_modificadores();

        int modificador(int id_item, int id_atributo);

        int Poder(int id_item);
        
        double Equilibrio(int id_item);


    private:
        MatrizEncadeada matriz_encadeada;
        MatrizCOO matriz_coo;
        enum class Modo_Matriz{
            TRIPLETAS,
            ENCADEADA
        };
        Modo_Matriz modo;
};

#endif