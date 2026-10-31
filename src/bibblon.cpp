#include "blibblon.hpp"

Blibblon::Blibblon()
{
    total_aventureiros = 0;
    total_itens = 0;
    total_atributos = 0;

    capacidade_aventureiros;
    capacidade_itens;
    capacidade_atributos;

    aventureiros = new Aventureiro*[capacidade_aventureiros];
    itens = new Item*[capacidade_itens];
    atributos = new Atributo*[capacidade_atributos];
}

Blibblon::~Blibblon()
{
    for (int i = 0; i < total_atributos; i++)
    {
        delete atributos[i];
    }

    for (int i = 0; i < total_itens; i++)
    {
        delete itens[i];
    }

    for (int i = 0; i < total_aventureiros; i++)
    {
        delete aventureiros[i];
    }

    delete[] atributos;
    delete[] itens;
    delete[] aventureiros;
}

void Blibblon::aumentar_aventureiros()
{
    capacidade_aventureiros *= 2;

    Aventureiro **novo = new Aventureiro*[capacidade_aventureiros];

    for (int i = 0; i < total_aventureiros; i++)
    {
        novo[i] = aventureiros[i];
    }

    delete[] aventureiros;
    aventureiros = novo;
}

void Blibblon::aumentar_atributos()
{
    capacidade_atributos *= 2;

    Atributo **novo = new Atributo*[capacidade_atributos];

    for (int i = 0; i < total_atributos; i++)
    {
        novo[i] = atributos[i];
    }

    delete[] atributos;
    atributos = novo;
}

void Blibblon::aumentar_itens()
{
    capacidade_itens *= 2;

    Item **novo = new Item*[capacidade_itens];

    for(int i = 0; i < total_itens; i++)
    {
        novo[i] = itens[i];
    }

    delete[] itens;
    itens = novo;
}

int Blibblon::A_cadastro_atributo(string nome)
{
    if(capacidade_atributos == total_atributos)
        aumentar_atributos();

    atributos[total_atributos] = new Atributo(total_atributos, nome);

    catalogo.cadastrar_atributo(total_atributos);

    total_atributos++;
    return total_atributos - 1;
}

int Blibblon::I_cadastro_item(string nome)
{
    if(capacidade_itens == total_itens)
        aumentar_itens();

    itens[total_itens] = new Item(total_itens, nome);

    catalogo.cadastrar_item(total_itens);

    total_itens++;
    return total_itens - 1;
}

int Blibblon::H_cadastro_aventureiro(string nome)
{
    if(capacidade_aventureiros == total_aventureiros)
        aumentar_aventureiros();

    aventureiros[total_aventureiros] = new Aventureiro(total_aventureiros, nome);

    total_aventureiros++;
    return total_aventureiros - 1;

}

string Blibblon::nome_item(int id_item)
{
    return itens[id_item]->get_nome();
}

string Blibblon::nome_atributo(int id_atributo)
{
    return atributos[id_atributo]->get_nome();
}

string Blibblon::nome_aventureiro(int id_aventureiro)
{
    return aventureiros[id_aventureiro]->get_nome();
}   

void Blibblon::E_modo(char modo)
{
    catalogo.E_modo(modo);
}

void Blibblon::M_modificador(int id_item, int id_atributo, int valor)
{
    catalogo.M_modificador(id_item, id_atributo, valor);
}

int Blibblon::LI_consulta(int id_item, int *atributos, int *modificadores)
{
    return catalogo.LA_consulta(id_item, atributos, modificadores);
}

int Blibblon::LA_consulta(int id_atributo, int *itens, int *modificadores)
{
    return catalogo.LI_consulta(id_atributo, itens, modificadores);
}
