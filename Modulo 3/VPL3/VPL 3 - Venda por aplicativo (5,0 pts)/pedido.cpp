#include <sstream>
#include "pedido.hpp"

using namespace std;

Pedido::~Pedido()
{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  while (this->m_produtos.empty() == 0)
  {
    delete this->m_produtos.front(), this->m_produtos.pop_front();
  }
}

void Pedido::setEndereco(const std::string &endereco)
{
  // TODO: Implemente este metodo.
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const
{
  // TODO: Implemente este metodo.
  float total = 0.0;
  std::list<Produto *>::const_iterator it;
  for (it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it)
  {
    total += (*it)->getQtd() * (*it)->getValor();
  }
  return total;
}

void Pedido::adicionaProduto(Produto *p)
{
  // TODO: Implemente este metodo.
  this->m_produtos.push_back(p);
}

std::string Pedido::resumo() const
{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  list<Produto *>::const_iterator it;
  ostringstream resumoPedido;
  for (it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it)
  {
    resumoPedido << (*it)->descricao() << endl;
  }
  resumoPedido << "Endereco: " << this->m_endereco << endl;

  return resumoPedido.str();
  ;
}