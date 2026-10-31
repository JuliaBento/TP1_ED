#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using namespace std;

class Item
{
    private:
        int id;
        string nome;

    public:
        Item(int id_, string nome_);

        int get_ID();
        string get_nome();
};

#endif