#ifndef AVENTUREIRO_HPP
#define AVENTUREIRO_HPP

#include "stack.hpp"
#include "catalogo.hpp"
#include <string>

using namespace std;

struct Estrutura_build{
    int id_atributo;
    int valor;
};

class Aventureiro {
    private:
        int id;
        string nome;

        Stack itens;
  
        Estrutura_build *build;
        int tamanho_build;
        int capacidade_build;

    public:
        Aventureiro(int id_, string nome_);
        void equipar(int id_item, Catalogo& catalogo);
        void desequipar(Catalogo& catalogo);
        void LH_consulta_build();
        void aumentar_build();
        double sinergia(int id_item, Catalogo& catalogo);
};

#endif