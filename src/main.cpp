#include <iostream>
#include <iomanip>
#include "catalogo.hpp"
#include "aventureiro.hpp"

using namespace std;

int main()
{
    Catalogo catalogo;

    catalogo.M_modificador(0, 2, 5);
    catalogo.M_modificador(0, 0, 3);

    catalogo.M_modificador(1, 1, 4);
    catalogo.M_modificador(1, 2, -2);

    catalogo.M_modificador(2, 3, 7);

    catalogo.E_modo('L');

    cout << "Total de modificadores: "
         << catalogo.quantidade_modificadores() << endl;

    Aventureiro aventureiro(0, "Guerreiro");

    cout << fixed << setprecision(6);

    cout << "\n===== TESTE 1: METRICAS ENCADEADA =====\n";

    for(int i = 0; i < 3; i++)
    {
        cout << "\nItem " << i << endl;
        cout << "Poder: " << catalogo.Poder(i) << endl;
        cout << "Equilibrio: " << catalogo.Equilibrio(i) << endl;
        cout << "Sinergia: " << aventureiro.sinergia(i, catalogo) << endl;
    }

    cout << "\n===== TESTE 2: EQUIPAR ITEM 0 =====\n";

    aventureiro.equipar(0, catalogo);
    aventureiro.LH_consulta_build();

    for(int i = 0; i < 3; i++)
    {
        cout << "Sinergia item " << i << ": "
             << aventureiro.sinergia(i, catalogo) << endl;
    }

    cout << "\n===== TESTE 3: EQUIPAR ITEM 1 =====\n";

    aventureiro.equipar(1, catalogo);
    aventureiro.LH_consulta_build();

    for(int i = 0; i < 3; i++)
    {
        cout << "Sinergia item " << i << ": "
             << aventureiro.sinergia(i, catalogo) << endl;
    }

    cout << "\n===== TESTE 4: DESEQUIPAR ITEM 1 =====\n";

    aventureiro.desequipar(catalogo);
    aventureiro.LH_consulta_build();

    for(int i = 0; i < 3; i++)
    {
        cout << "Sinergia item " << i << ": "
             << aventureiro.sinergia(i, catalogo) << endl;
    }

    cout << "\n===== TESTE 5: DESEQUIPAR ITEM 0 =====\n";

    aventureiro.desequipar(catalogo);
    aventureiro.LH_consulta_build();

    for(int i = 0; i < 3; i++)
    {
        cout << "Sinergia item " << i << ": "
             << aventureiro.sinergia(i, catalogo) << endl;
    }

    cout << "\n===== FIM DOS TESTES ENCADEADA =====\n";

    return 0;
}