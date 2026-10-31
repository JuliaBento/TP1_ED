#pragma once
#ifndef MATRIZENCADEADA_HPP
#define MATRIZENCADEDADA_HPP

using namespace std;

struct Celula
{
    int lin, col, val;
    Celula *proxLin; // proxima celula na mesma linha (coluna maior)
    Celula *proxCol; // proxima celula na mesma coluna (linha maior)
};

class MatrizEncadeada
{
public:
    MatrizEncadeada();
    ~MatrizEncadeada();
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
    
    int l, c, tamanho;

private:
    Celula **cabLin;                      // cabLin[i]: celula cabeca da linha i
    Celula **cabCol;                      // cabCol[j]: celula cabeca da coluna j
    Celula *AntLinha(int i, int j) const; 
    Celula *AntColuna(int i, int j) const;
};

#endif