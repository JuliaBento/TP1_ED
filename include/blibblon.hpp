#ifndef BLIBBLON_HPP
#define BLIBBLON_HPP
#include "aventureiro.hpp"
#include "item.hpp"
#include "atributo.hpp"
#include "catalogo.hpp"

class Blibblon
{
    private:
        Aventureiro **aventureiros;
        Item **itens;
        Atributo **atributos;
        Catalogo catalogo;

        int total_aventureiros;
        int total_itens;
        int total_atributos;

        int capacidade_aventureiros;
        int capacidade_itens;
        int capacidade_atributos;

    public:
        Blibblon();
        ~Blibblon();
        void aumentar_itens();
        void aumentar_atributos();
        void aumentar_aventureiros();
        int A_cadastro_atributo(string nome);
        int I_cadastro_item(string nome);
        int H_cadastro_aventureiro(string nome);
        void E_modo(char modo);
        void M_modificador(int id_item, int id_atributo, int valor);
        int LI_consulta(int id_item, int *atributos, int *modificadores);
        int LA_consulta(int id_atributo, int *itens, int *modificadores);


        string nome_item(int id_item);
        string nome_atributo(int id_atributo);
        string nome_aventureiro(int id_aventureiro);
};

#endif