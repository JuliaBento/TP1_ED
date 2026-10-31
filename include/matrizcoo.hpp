#ifndef MATRIZCOO_HPP
#define MATRIZCOO_HPP

using namespace std;

class MatrizCOO
{
public:
    MatrizCOO();
    ~MatrizCOO();
    int Get(int i, int j) const;
    void Set(int i, int j, int v);
    void limpar();    
    void AdicionarAtributo(int id_atributo);
    void AdicionarItem(int id_item);
    int atributos_item(int id_item, int *atributes, int *modifiers);//LA: Discover all atributes an item modifies (Line values)
    int itens_atributo(int id_atributo, int *items, int *modifiers);//LI: Discover all itens that modify an attibute (Column values)
    int Soma(int id_item, int * nao_nulos = nullptr);//sum of one item's modifiers and measures how many 0 atributes it has
    double Desvio(int id_item);//method to help calculates Equilíbrio
    int Produto(int id_item1, int id_item2);

    int l, c;       // dimensoes da matriz representada
    int tamanho;    // k = triples with non-zero values
    int tamanhoMAX; // vector size of the arrays
    int *linhas;    // items
    int *colunas;   // atributes
    int *valores;   // modifiers

private:
    void InsereElemento(int i, int j, int v);//insert element in the right position 
    void RemoveElemento(int p);//We copy the next element on the place of one we want to remove and so on
    void Cresce(); //Doubles the size of the arrays 
};

#endif