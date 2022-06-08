#include "hamburguer.hpp"
#include <sstream>

std::string Hamburguer::descricao() const
{
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */

  std::ostringstream s_descricao;
  s_descricao << std::to_string(this->getQtd()) << "X "
              << "Hamburguer " << this->tipo;
  if (this->artesanal)
    s_descricao << " artesanal";
  else
    s_descricao << " simples";

  return s_descricao.str();
}

Hamburguer::Hamburguer(const std::string &tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario)
{
  // TODO: Implemente este metodo.
  this->tipo = tipo;
  this->artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}