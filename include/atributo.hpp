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
};

#endif