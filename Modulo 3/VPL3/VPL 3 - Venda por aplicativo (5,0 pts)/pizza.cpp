#include "pizza.hpp"
#include <sstream>

std::string Pizza::descricao() const
{
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  std::ostringstream s_descricao;
  s_descricao << std::to_string(this->getQtd()) << "X "
              << "Pizza " << this->sabor << ", " << std::to_string(this->pedacos) << " pedacos ";

  if (this->borda_recheada == 1)
  {
    s_descricao << "e borda recheada.";
  }
  else
  {
    s_descricao << "e sem borda recheada";
  }
  return s_descricao.str();
}

Pizza::Pizza(const std::string &sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario)
{
  // TODO: Implemente este metodo.

  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}