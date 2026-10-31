#include "atributo.hpp"

using namespace std;

Atributo::Atributo(int id, string nome) {
    this->id = id;
    this->nome = nome;
}


int Atributo::get_ID()
{
    return this->id;
}


string Atributo::get_nome()
{
    return this->nome;
}