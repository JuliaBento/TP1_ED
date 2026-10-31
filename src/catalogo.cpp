#include "catalogo.hpp"
#include <iostream>

using namespace std;

Catalogo::Catalogo():modo(Modo_Matriz::TRIPLETAS)
{
 
}

void Catalogo::E_modo(char modo)
{
    Modo_Matriz modo_antigo = this->modo;

    if((modo == 'T' && this->modo == Modo_Matriz::TRIPLETAS) ||
       (modo == 'L' && this->modo == Modo_Matriz::ENCADEADA))
        return; 
       
    limpar_matriz(); //Cleaning destine matrix
    
    if(modo_antigo == Modo_Matriz::TRIPLETAS){
        if(matriz_coo.l > 0)
            matriz_encadeada.AdicionarItem(matriz_coo.l -1);

        if(matriz_coo.c > 0)
            matriz_encadeada.AdicionarAtributo(matriz_coo.c -1);

        for(int i = 0; i < matriz_coo.tamanho; i++) {
            {
                int linha  = matriz_coo.linhas[i];
                int coluna = matriz_coo.colunas[i];
                int mod    = matriz_coo.valores[i];

                matriz_encadeada.Set(linha, coluna, mod);  
            }
        }
    } 
    else 
    {
        if(matriz_encadeada.l > 0)
            matriz_coo.AdicionarItem(matriz_encadeada.l -1);

        if(matriz_encadeada.c > 0)
            matriz_coo.AdicionarAtributo(matriz_encadeada.c -1);

        for(int i = 0; i < matriz_encadeada.l; i++)
        {
            int *atributes = new int[matriz_encadeada.c];
            int *modifiers = new int[matriz_encadeada.c];

            int quantidade = matriz_encadeada.atributos_item(i, atributes, modifiers);

            for(int p = 0; p < quantidade; p++)
            {
                matriz_coo.Set(i, atributes[p], modifiers[p]);
            }
            delete[] atributes;
            delete[] modifiers;
        }   
    } 

    if(modo == 'T')
        this->modo = Modo_Matriz::TRIPLETAS;
    else 
        this->modo = Modo_Matriz::ENCADEADA;
}

void Catalogo::limpar_matriz()
{
    if(this->modo == Modo_Matriz::TRIPLETAS){
        matriz_encadeada.limpar();
    }
    else if(this->modo == Modo_Matriz::ENCADEADA){
        matriz_coo.limpar();
    }
}

void Catalogo::M_modificador(int id_item, int id_atributo, int valor)
{
    if(this->modo == Modo_Matriz::TRIPLETAS){
        matriz_coo.AdicionarAtributo(id_atributo);
        matriz_coo.AdicionarItem(id_item);
        matriz_coo.Set(id_item, id_atributo, valor);
    }
    else if(this->modo == Modo_Matriz::ENCADEADA){
        matriz_encadeada.AdicionarAtributo(id_atributo);
        matriz_encadeada.AdicionarItem(id_item);
        matriz_encadeada.Set(id_item, id_atributo, valor);
    }
}

int Catalogo::LI_consulta(int id_atributo, int* itens, int* modificadores)
{
    if(this->modo == Modo_Matriz::TRIPLETAS)
    {
        return matriz_coo.itens_atributo(id_atributo, itens, modificadores);
    }
    return matriz_encadeada.itens_atributo(id_atributo, itens, modificadores);
}

int Catalogo::LA_consulta(int id_item, int* atributos, int* modificadores)
{
    if(this->modo == Modo_Matriz::TRIPLETAS)
    {
        return matriz_coo.atributos_item(id_item, atributos, modificadores);
    }
    return matriz_encadeada.atributos_item(id_item, atributos, modificadores);
}

int Catalogo::quantidade_modificadores()
{
    if (this->modo == Modo_Matriz::TRIPLETAS)
    {
        return matriz_coo.tamanho;
    }
    return matriz_encadeada.tamanho;
}

int Catalogo::get_modificador(int id_item, int id_atributo)
{
    if(modo == Modo_Matriz::TRIPLETAS)
        return matriz_coo.Get(id_item, id_atributo);

    return matriz_encadeada.Get(id_item, id_atributo);
}

int Catalogo::Poder(int id_item)
{
    if(modo == Modo_Matriz::TRIPLETAS)
        return matriz_coo.Soma(id_item);

    return matriz_encadeada.Soma(id_item);
}

double Catalogo::Equilibrio(int id_item)
{
    double desvio;

    if(modo == Modo_Matriz::TRIPLETAS)
        desvio = matriz_coo.Desvio(id_item);
    else
        desvio = matriz_encadeada.Desvio(id_item);

    return 1.0 / (1.0 + desvio);
}

void Catalogo::cadastrar_item(int id_item)
{
    if (modo == Modo_Matriz::TRIPLETAS)
        matriz_coo.AdicionarItem(id_item);
    else
        matriz_encadeada.AdicionarItem(id_item);
}
    
void Catalogo::cadastrar_atributo(int id_atributo)
{
    if (modo == Modo_Matriz::TRIPLETAS)
        matriz_coo.AdicionarAtributo(id_atributo);
    else
        matriz_encadeada.AdicionarAtributo(id_atributo);
}