#include <iostream>
#include "Processo.hpp"

Processo::Processo(){

}

Processo::Processo(int id, std::string nome, int prioridade)
{
    this->_id = id;
    this->_nome = nome;
    this->_prioridade = prioridade;
}

void Processo::imprimir_dados(){
    std::cout << this->_id << " " << this->_nome << " " << this->_prioridade << std::endl;
}