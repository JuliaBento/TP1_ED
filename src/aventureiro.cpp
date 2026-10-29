#include "aventureiro.hpp"

using namespace std;

Aventureiro::Aventureiro(int id_, string nome_)
{
    id = id_;
    nome = nome_;
    capacidade_build = 0;
    tamanho_build = 0;
    build = nullptr;
}

void Aventureiro::equipar(int id_item, Catalogo& catalogo)
{
    //Add item in the stack
    Node * novo = new Node(id_item);
    itens.push(novo);

    //Add modifier to the build
    int capacidade = catalogo.quantidade_modificadores();
    int* atributos = new int[capacidade];
    int* modificadores = new int[capacidade];

    int total_atributos = catalogo.LA_consulta(id_item, atributos, modificadores);

    for(int i = 0; i < total_atributos; i++)
    {
        bool existe = false;

        for(int j = 0; j < tamanho_build; j++)
        {
            if(build[j].id_atributo == atributos[i])
            {
                build[j].valor += modificadores[i];
                existe = true;
                break;
            }
        }

        if(!existe)
        {
            if(tamanho_build == capacidade_build)
            {
                aumentar_build();
            }
            build[tamanho_build].id_atributo = atributos[i];
            build[tamanho_build].valor = modificadores[i];
            tamanho_build++;
        }
    }
    delete[] atributos;
    delete[] modificadores;
}

void Aventureiro::desequipar(Catalogo& catalogo)
{
    //Take the item off
    if (itens.isEmpty())
        throw "Pilha vazia";

    Node* removido = itens.pop();
    int id_item = removido->key;
    delete removido;

    //Subtract modifiers
    int capacidade = catalogo.quantidade_modificadores();
    int* atributos = new int[capacidade];
    int* modificadores = new int[capacidade];

    int total_atributos = catalogo.LI_consulta(id_item, atributos, modificadores);

    for(int i = 0; i < total_atributos; i++)
    {
        for(int j = 0; j < tamanho_build; j++)
        {
            if(build[j].id_atributo == atributos[i])
            {
                build[j].valor -= modificadores[i];

                bool permanece = false;

                Node* atual = itens.peek();

                while(atual != nullptr)
                {
                    if(catalogo.modificador(atual->key, atributos[i]) != 0)
                    {
                        permanece = true;
                        break;
                    }

                    atual = atual->next;
                }

                if(!permanece)
                {
                    for(int k = j; k < tamanho_build - 1; k++)
                    {
                        build[k] = build[k + 1];
                    }

                    tamanho_build--;
                }

                break;
            }
        }
    }

    delete[] atributos;
    delete[] modificadores;
}

void Aventureiro::LH_consulta_build()
{

}

void Aventureiro::aumentar_build()
{
    if(capacidade_build == 0)
    { 
        capacidade_build = 1;
    } else
    {
        capacidade_build = capacidade_build * 2;
    }
    
    Estrutura_build* nova_build = new Estrutura_build[capacidade_build];

    for(int i = 0; i < tamanho_build; i++)
    {
        nova_build[i] = build[i];
    }

    delete[] build;
    build = nova_build;
}

double Aventureiro::sinergia(int id_item, Catalogo& catalogo)
{

}