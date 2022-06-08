// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"

#include "ListaProcessos.hpp"
#include "Processo.hpp"

#include <iostream>

int main()
{

    char nome_t[15];
    int idd;
    int priori;
    char data = 'h';
    ListaProcessos lista;
    while (cin >> data)
    {
        switch (data)
        {
        case 'a':
            cin >> idd >> nome_t >> priori;
            lista.adicionar_processo(new Processo(idd, nome_t, priori));
            cout << idd << nome_t << priori;

            break;

        case 'm':
            lista.remover_processo_maior_prioridade();
            break;
        case 'n':
            lista.remover_processo_menor_prioridade();
            break;
        case 'r':
            cin >> idd;
            lista.remover_processo_por_id(idd);
            break;
        case 'p':
            lista.imprimir_lista();

            break;

        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}