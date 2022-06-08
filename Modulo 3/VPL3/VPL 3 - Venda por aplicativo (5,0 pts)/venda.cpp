#include "venda.hpp"

#include <iomanip>

using namespace std;

Venda::~Venda()
{
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  while (this->m_pedidos.empty() == 0)
  {
    delete this->m_pedidos.front(), this->m_pedidos.pop_front();
  }
}

void Venda::adicionaPedido(Pedido *p)
{
  // TODO: Implemente este metodo
  this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const
{
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  int numOfOrder = 0;
  float totalOfOrder = 0.0;
  std::list<Pedido *>::const_iterator it;
  for (it = this->m_pedidos.begin(); it != this->m_pedidos.end(); ++it)
  {
    numOfOrder++;
    cout << "Pedido " << numOfOrder << endl
         << (*it)->resumo();
    totalOfOrder += (*it)->calculaTotal();
  }
  cout << "Relatorio de Vendas" << std::endl
       << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << totalOfOrder << endl
       << "Total de pedidos: " << numOfOrder;
}