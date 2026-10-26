#include "matrizEncadeada.hpp"
#include <cmath>

using namespace std;

MatrizEncadeada::MatrizEncadeada()
{
    l = 0;
    c = 0;
    tamanho = 0;
    cabLin = new Celula *[l];
    cabCol = new Celula *[c];
    for (int i = 0; i < l; i++)
        cabLin[i] = new Celula{i, -1, 0, nullptr, nullptr};
    for (int j = 0; j < c; j++)
        cabCol[j] = new Celula{-1, j, 0, nullptr, nullptr};
}

MatrizEncadeada::~MatrizEncadeada()
{
    for (int i = 0; i < l; i++)
    { // pelas linhas
        Celula *p = cabLin[i];
        while (p != nullptr)
        {
            Celula *q = p->proxLin;
            delete p;
            p = q;
        }
    }
    for (int j = 0; j < c; j++)
        delete cabCol[j];
    // free vector's pointers
    delete[] cabLin;
    delete[] cabCol;
}

Celula *MatrizEncadeada::AntLinha(int i, int j) const
{
    Celula *p = cabLin[i];
    while (p->proxLin != nullptr && p->proxLin->col < j)
        p = p->proxLin;
    return p;
}

Celula *MatrizEncadeada::AntColuna(int i, int j) const
{
    Celula *p = cabCol[j];
    while (p->proxCol != nullptr && p->proxCol->lin < i)
        p = p->proxCol;
    return p;
}

int MatrizEncadeada::Get(int i, int j) const
{
    if (i < 0 || i >= l || j < 0 || j >= c)
    {
        throw "Posicao invalida";
    }

    Celula *ant = AntLinha(i, j);
    Celula *p = ant->proxLin;
    if (p != nullptr && p->col == j)
        return p->val;
    return 0;
}

void MatrizEncadeada::Set(int i, int j, int v)
{
    if (i < 0 || i >= l || j < 0 || j >= c)
    {
        throw "Posicao invalida";
    }

    Celula *antL = AntLinha(i, j);
    Celula *antC = AntColuna(i, j);
    Celula *p = antL->proxLin;

    // Cell exists
    if (p != nullptr && p->col == j)
    { // change value
        if (v != 0)
        {
            p->val = v;
            return;
        }
        // exclude cell
        antL->proxLin = p->proxLin; // desliga da linha
        antC->proxCol = p->proxCol; // desliga da coluna
        delete p;
        tamanho--;
        return;
    }

    // Cell doesn't exist
    if (v == 0) // We don't manage zero values
        return;
    Celula *nova = new Celula{i, j, v,
                              antL->proxLin, antC->proxCol};
    antL->proxLin = nova; // liga na linha
    antC->proxCol = nova; // liga na coluna
    tamanho++;
}

void MatrizEncadeada::limpar()
{
    
}

void MatrizEncadeada::AdicionarAtributo(int id_atributo)
{
    int anterior = c;

    // updates c
    if ((id_atributo + 1) > c)
    {
        c = (id_atributo + 1);

        Celula **novo = new Celula *[c];

        for (int j = 0; j < anterior; j++)
            novo[j] = cabCol[j];

        delete[] cabCol;
        cabCol = novo;
    }

    // updates head pointers
    for (int j = anterior; j < c; j++)
        cabCol[j] = new Celula{-1, j, 0, nullptr, nullptr};
}

void MatrizEncadeada::AdicionarItem(int id_item)
{
    int anterior = l;

    // updates l
    if ((id_item + 1) > l)
    {
        l = (id_item + 1);

        Celula **novo = new Celula *[l];

        for (int i = 0; i < anterior; i++)
            novo[i] = cabLin[i];

        delete[] cabLin;
        cabLin = novo;
    }

    // updates head pointers
    for (int i = anterior; i < l; i++)
        cabLin[i] = new Celula{i, -1, 0, nullptr, nullptr};
}

int MatrizEncadeada::atributos_item(int id_item, int *atributes, int *modifiers)
{
    int count = 0; // Total modifiers

    Celula *atual = cabLin[id_item]->proxLin;

    while (atual != nullptr)
    {
        atributes[count] = atual->col;
        modifiers[count] = atual->val;

        count++;
        atual = atual->proxLin;
    }
    return count;
}

int MatrizEncadeada::itens_atributo(int id_atributo, int *items, int *modifiers)
{
    int count = 0;

    Celula *atual = cabCol[id_atributo]->proxCol;

    while (atual != nullptr)
    {
        items[count] = atual->lin;
        modifiers[count] = atual->val;

        count++;
        atual = atual->proxCol;
    }
    return count;
}

int MatrizEncadeada::Soma(int id_item, int *nao_nulos)
{
    int total = 0;

    Celula *atual = cabLin[id_item]->proxLin;

    while (atual != nullptr)
    {
        total += atual->val;

        if (nao_nulos != nullptr)
        {
            (*nao_nulos)++;
        }

        atual = atual->proxLin;
    }
    return total;
}

double MatrizEncadeada::Desvio(int id_item)
{
    if (c == 0)
    {
        return 0;
    }

    double desvio = 0.00;
    int nao_nulos = 0;
    int poder = Soma(id_item, &nao_nulos);         // to calculate PODER()
    double media = static_cast<double>(poder) / c; // correction of type to preserve decimal places

    Celula *atual = cabLin[id_item]->proxLin;

    while (atual != nullptr)
    {
        desvio += (atual->val - media) * (atual->val - media);
        atual = atual->proxLin;
    }

    desvio += ((c - nao_nulos) * ((0 - media) * (0 - media))); // to deal with 0 atributes
    desvio = sqrt(desvio / static_cast<double>(c));

    return desvio;
}

int MatrizEncadeada::Produto(int id_item1, int id_item2)
{
    int result = 0;

    Celula *atual1 = cabLin[id_item1]->proxLin;
    Celula *atual2 = cabLin[id_item2]->proxLin;

    while (atual1 != nullptr && atual2 != nullptr)
    {
        if (atual1->col == atual2->col)
        {
            result += atual1->val * atual2->val;

            atual1 = atual1->proxLin;
            atual2 = atual2->proxLin;
        }
        else if (atual1->col > atual2->col)
        {
            atual2 = atual2->proxLin;
        }
        else if (atual1->col < atual2->col)
        {
            atual1 = atual1->proxLin;
        }
    }

    return result;
}