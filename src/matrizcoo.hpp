#ifndef MATRIZCOO_HPP
#define MATRIZCOO_HPP

using namespace std;

class MatrizCOO
{
public:
    MatrizCOO(int linhas, int colunas);

    ~MatrizCOO();

    int Get(int i, int j) const;

    void Set(int i, int j, int v);

    void Imprime() const;

    void LeMatriz();

    static void Soma(const MatrizCOO &A, const MatrizCOO &B, MatrizCOO &C);

    static double *Produto(const MatrizCOO &A, const int *u, int n);

    //LA: Discover all atributes an item modifies  
    int atributos_item(int id_item, int *atributes, int *modifiers); //Line values

    //LA: Discover all itens that modify an attibute
    int itens_atributo(int id_atributo, int *items, int *modifiers); //Column values

    int l, c;       // dimensoes da matriz representada
    int tamanho;    // k = triples with non-zero values
    int tamanhoMAX; // vector size of the arrays
    int *linhas;    // items
    int *colunas;   // atributes
    int *valores;   // modifiers

private:
    //insert element in the right position 
    void InsereElemento(int i, int j, int v);
   
    //We copy the next element on the place of one we want to remove and so on
    void RemoveElemento(int p);
    
    void Cresce(); //Doubles the size of the arrays 
};

#endif