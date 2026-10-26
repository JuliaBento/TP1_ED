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

        void LI_consulta(int id_item);

        void LA_consulta(int id_atributo);


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