#include "catalogo.hpp"
#include <iostream>

using namespace std;

Catalogo::Catalogo():modo(Modo_Matriz::TRIPLETAS)
{
        
}

void Catalogo::E_modo(char modo)
{
    if(modo == 'T')
        this->modo = Modo_Matriz::TRIPLETAS;

    if(modo == 'L')
        this->modo = Modo_Matriz::ENCADEADA;

}

void Catalogo::limpar_matriz()
{
    if(this->modo == Modo_Matriz::TRIPLETAS){
        for()
        matriz_coo.Set()
    }
    else if(this->modo == Modo_Matriz::ENCADEADA){

    }
}

void Catalogo::M_modificador(int id_item, int id_atributo, int valor)
{
    if(this->modo == Modo_Matriz::TRIPLETAS){
        matriz_coo.AdicionarAtributo(id_atributo);
        matriz_coo.AdicionarItem(id_item);
        matriz_coo.Set(id_item, id_atributo, valor);
    }
    else if(this->modo == Modo_Matriz::ENCADEADA){
        matriz_coo.AdicionarAtributo(id_atributo);
        matriz_coo.AdicionarItem(id_item);
        matriz_encadeada.Set(id_item, id_atributo, valor);
    }
}

void         void A_cadastro_atributo(int id_atributo);


