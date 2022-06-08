#ifndef LISTAPROCESSOS_H
#define LISTAPROCESSOS_H

#include <iostream>
#include "Processo.hpp"

using namespace std;

struct NodeT{
    Processo processo;
    NodeT* esq;
    NodeT* dir;
};

struct ListaProcessos
{
    NodeT* raiz = nullptr;
    
    void adicionar_processo(Processo* proc);
    void adicionar_processo_recursivo(NodeT* n, Processo processo);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void imprimir_lista();
    void imprimir_lista(NodeT* n);
};


#endif