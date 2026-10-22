#ifndef AVENTUREIRO_HPP
#define AVENTUREIRO_HPP

class Aventureiro {
    private:
        int id;
        string nome;
        

    public:
        Aventureiro(int id, string nome);
        desequipar();
        equipar(int id_item);
        consulta_build();
        sinergia();
}

#endif