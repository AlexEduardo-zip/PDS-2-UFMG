#include "ListaProcessos.hpp"
#include <iostream>

NodeT *cria_processo(Processo processo)
{
    NodeT *aux = new NodeT;
    aux->processo = processo;
    aux->dir = nullptr;


    return aux;
}

void ListaProcessos::adicionar_processo(Processo *proc)
{
    if (raiz != nullptr)
    {
        if (proc->_prioridade > raiz->processo._prioridade)
    {
        if (n->dir == nullptr)
        {
            n->dir == cria_processo(proc);
        }
        else
        
    }
    else
    {
        raiz = cria_processo(*proc);
    }
}

void ListaProcessos::adicionar_processo_recursivo(NodeT *n, Processo proc)
{
    if (proc._prioridade < n->processo._prioridade)
    {
        if (n->esq == nullptr)
        {
            n->esq = cria_processo(proc);
        }
        else
        {
            adicionar_processo_recursivo(n->esq, proc);
        }
    }
    else if (proc._prioridade > n->processo._prioridade)
    {
        if (n->dir == nullptr)
        {
            n->dir == cria_processo(proc);
        }
        else
        {
            adicionar_processo_recursivo(n->dir, proc);
        }
    }
}

Processo *ListaProcessos::remover_processo_maior_prioridade()
{
    NodeT *aux = raiz;
    while (aux != nullptr)
    {
        aux = aux->esq;
    }
    return &aux->dir->processo;
    aux->dir = nullptr;
}

Processo *ListaProcessos::remover_processo_menor_prioridade()
{
    NodeT *aux = raiz;
    while (aux != nullptr)
    {
        aux = aux->dir;
    }
    return &aux->esq->processo;
    aux->esq = nullptr;
}

Processo *ListaProcessos::remover_processo_por_id(int id)
{
    NodeT *aux = raiz;
    int achou;
    while (aux != nullptr)
    {
        aux = aux->esq;
    }
    while (achou != 1)
    {
        if (aux->processo._id == id)
        {
            achou = 1;
            break;
        }
        aux = aux->dir;
    }
    return &aux->processo;
    aux = nullptr;
}

void ListaProcessos::imprimir_lista()
{
    NodeT *aux = raiz;
    while (aux != nullptr)
    {
        aux->processo.imprimir_dados();
        aux = aux->esq;
    }
    NodeT *aux2 = raiz;
    while (aux != nullptr)
    {
        aux2->processo.imprimir_dados();
        aux2 = aux->dir;
    }
    //imprimir_lista(this->raiz);
}

//void ListaProcessos::imprimir_lista(NodeT *n)
//{
//
//    if (n == nullptr)
//   {
//       return;
//  }
// imprimir_lista(n->esq);
// n->processo.imprimir_dados();
//imprimir_lista(n->dir);

//NodeT *aux = raiz;
//while (aux != nullptr)
//{
//    aux = aux->esq;
//}
//aux = aux->dir;
//while (aux != nullptr)
//{
//    aux->processo.imprimir_dados();
//}
