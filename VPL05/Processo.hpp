#ifndef PROCESSO_H
#define PROCESSO_H

#include <string>

struct Processo
{
    int _id;
    int _prioridade; 
    std::string _nome;

    Processo();
    Processo(int id, std::string nome, int prioridade);

    void imprimir_dados(); //Método que faz a impressão dos atributos no seguinte formato: "id nome prioridade", com uma quebra de linha ao final.
};


#endif