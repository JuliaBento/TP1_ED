#include "matrizcoo.hpp"
#include <iostream>
#include <cmath>

using namespace std;

MatrizCOO::MatrizCOO()
{
    l = 0;
    c = 0;
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

void MatrizCOO::AdicionarAtributo(int id_atributo)
{
    if ((id_atributo + 1) > c){
        c = (id_atributo + 1);
    }
}

void MatrizCOO::AdicionarItem(int id_item)
{
    if ((id_item + 1) > l){
        l = (id_item + 1);
    }
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

int MatrizCOO::Soma(int id_item, int * nao_nulos)
{
    int total = 0; 
    for (int i = 0; i < tamanho; i++) {
        if(linhas[i] == id_item)
        {
            total += valores[i];
            
            if (nao_nulos != nullptr)
            {
                (*nao_nulos)++;
            }
        }
    }
    return total;
}

double MatrizCOO::Desvio(int id_item)
{
    if(c == 0){
        return 0;
    }

    double desvio = 0.00; 
    int nao_nulos = 0;
    int poder = Soma(id_item, &nao_nulos); //to calculate PODER()
    double media = static_cast<double>(poder) / c; //correction of type to preserve decimal places
    
    for (int i = 0; i < tamanho; i++) {
        if(linhas[i] == id_item)
        {
            desvio += (valores[i] - media) * (valores[i] - media);
        }
    }
    desvio += ((c - nao_nulos) * ((0 - media) * (0 - media))); //to deal with 0 atributes 
    desvio = sqrt(desvio/ static_cast<double>(c));

    return desvio;   
}

int MatrizCOO::Produto(int id_item1, int id_item2)
{
    int result = 0;

    int id_atributos1[c]; 
    int valores_atributos1[c];

    int id_atributos2[c]; 
    int valores_atributos2[c];

    int total_atrib1 = atributos_item(id_item1, id_atributos1, valores_atributos1);
    int total_atrib2 = atributos_item(id_item2, id_atributos2, valores_atributos2); 
  

    for(int i = 0; i < total_atrib1; i++){
        for (int j = 0; j < total_atrib2; j++){
            if(id_atributos1[i] == id_atributos2[j]){
                result += valores_atributos1[i] * valores_atributos2[j];
            }
        }
    }
    return result;
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
