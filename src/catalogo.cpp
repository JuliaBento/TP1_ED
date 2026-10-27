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
        throw "Matriz já está nesse modo";
    
    limpar_matriz(); //Cleaning destine matrix
    
    if(modo_antigo == Modo_Matriz::ENCADEADA){
        for(int i = 0; i < matriz_coo.tamanho; i++) {
            {
                int linha  = matriz_coo.linhas[i];
                int coluna = matriz_coo.colunas[i];
                int mod    = matriz_coo.valores[i];
                
                matriz_encadeada.AdicionarItem(linha);
                matriz_encadeada.AdicionarAtributo(coluna);
                matriz_encadeada.Set(linha, coluna, mod);  
            }
        }
    } 
    else 
    {
        for(int i = 0; i < matriz_encadeada.l; i++)
        {
            int *atributes = new int[matriz_encadeada.c];
            int *modifiers = new int[matriz_encadeada.c];

            int quantidade = matriz_encadeada.atributos_item(i, atributes, modifiers);

            for(int p = 0; p < quantidade; p++)
            {
                matriz_coo.AdicionarItem(i);
                matriz_coo.AdicionarAtributo(atributes[p]);
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

void Catalogo::LI_consulta(int id_item)
{
    
}

void Catalogo::LA_consulta(int id_atributo)
{

}



