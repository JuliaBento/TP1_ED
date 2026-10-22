#include "matrizcoo.hpp"
#include <iostream>

using namespace std;

MatrizCOO::MatrizCOO(int linhas_, int colunas_)
{
    l = linhas_;
    c = colunas_;
    tamanho = 0;
    tamanhoMAX = 4; //Little initial size by default 
    linhas = new int[tamanhoMAX];
    colunas = new int[tamanhoMAX];
    valores = new int[tamanhoMAX];
}

MatrizCOO::~MatrizCOO()
{
    delete[] linhas;
    delete[] colunas;
    delete[] valores;
}

int MatrizCOO::Get(int i, int j) const
{
    if (i < 0 || i >= l || j < 0 || j >= c)
    {
        throw "Posicao invalida";
    }
    for (int p = 0; p < tamanho; p++)
    {
        if (linhas[p] == i && colunas[p] == j)
        {
            return valores[p];
        }
    }
    return 0;
}

void MatrizCOO::Set(int i, int j, int v)
{
    if (i < 0 || i >= l || j < 0 || j >= c)
    {
        throw "Posicao invalida";
    }
    for (int p = 0; p < tamanho; p++){
        if (linhas[p] == i && colunas[p] == j)
        {
            if (v == 0)
                RemoveElemento(p);
            else
                valores[p] = v;
            return;
        }
    }
    if (v != 0) InsereElemento(i, j, v);

}

void MatrizCOO::Imprime() const
{
    int p = 0; 
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (p < tamanho && linhas[p] == i
                && colunas[p] == j) {
                cout << valores[p] << " ";
                p++;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void MatrizCOO::LeMatriz()
{
    int x;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> x;
            if (x != 0) InsereElemento(i, j, x);
        }
}

void MatrizCOO::Soma(const MatrizCOO &A, const MatrizCOO &B, MatrizCOO &C)
{
}

double *MatrizCOO::Produto(const MatrizCOO &A, const int *u, int n)
{
}


int MatrizCOO::atributos_item(int id_item, int *atributes, int *modifiers)
{
    int count = 0; //Total modifiers
    for (int i = 0; i < tamanho; i++) {
        if(linhas[i] == id_item)
        {
            atributes[count] = colunas[i];
            modifiers[count] = valores[i];
            count++;
        }
    }
    return count;
} 

int MatrizCOO::itens_atributo(int id_atributo, int *items, int *modifiers)
{
    int count = 0; //Total modifiers
    for (int i = 0; i < tamanho; i++) {
        if(colunas[i] == id_atributo)
        {
            items[count] = linhas[i];
            modifiers[count] = valores[i];
            count++;
        }
    }
    return count;
} 

void MatrizCOO::InsereElemento(int i, int j, int v)
{
    if(tamanho == tamanhoMAX) Cresce();
    int p = tamanho; //p = current position
    while (p > 0 && (linhas[p-1] > i || 
          (linhas[p-1] == i && colunas[p-1] > j))){
        linhas[p] = linhas[p-1];
        colunas[p] = colunas[p-1];
        valores[p] = valores[p-1];
        p--;
    }
    linhas[p] = i; 
    colunas[p] = j;
    valores[p] = v;
    tamanho++;
}

void MatrizCOO::RemoveElemento(int p)
{
    for(int q = p; q < tamanho-1; q++){
        linhas[q] = linhas[q+1];
        colunas[q] = colunas[q+1];
        valores[q] = valores[q+1];
    }
    tamanho--;
}

void MatrizCOO::Cresce()
{
    int novo = 2 * tamanhoMAX;
    int *nl = new int[novo];
    int *nc = new int[novo];
    int *nv = new int[novo];
    for(int i = 0; i < tamanho; i++){
        nl[i] = linhas[i];
        nc[i] = colunas[i];
        nv[i] = valores[i];
    }
    delete[] linhas;
    delete[] colunas;
    delete[] valores;
    linhas = nl;
    colunas = nc;
    valores = nv;
    tamanhoMAX = novo;
}
