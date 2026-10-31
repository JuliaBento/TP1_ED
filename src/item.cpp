#include "item.hpp"

Item::Item(int id_, string nome_)
{
    this->id = id_;
    this->nome = nome_;
}

int Item::get_ID()
{
    return id;
}

string Item::get_nome()
{
    return nome;
}