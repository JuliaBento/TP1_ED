#ifndef ATRIBUTO_HPP
#define ATRIBUTO_HPP
#include <string>

using namespace std;

class Atributo {
    private:
        int id;
        string nome;

    public:
        Atributo(int id, string nome);

        int get_ID();
        string get_nome();
};

#endif