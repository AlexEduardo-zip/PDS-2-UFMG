#include "japonesa.hpp"
#include "sstream"

std::string Japonesa::descricao() const
{
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  std::ostringstream s_descricao;
  s_descricao << std::to_string(this->getQtd()) << "X "
              << "Comida Japonesa - " << this->combinado << ", " << std::to_string(this->sushi) << " sushis, " << std::to_string(this->temaki) << " temakis e " << std::to_string(this->hots) << " hots.";

  return s_descricao.str();
}

Japonesa::Japonesa(const std::string &combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario)
{
  // TODO: Implemente este metodo.

  this->combinado = combinado;
  this->sushi = sushis;
  this->temaki = temakis;
  this->hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}