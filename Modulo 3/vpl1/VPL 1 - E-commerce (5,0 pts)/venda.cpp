#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular &celular)
{
  // TODO: Implemente este metodo
  m_celulares.push_back(celular);
}

void Venda::ordena()
{
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd)
{
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it = m_celulares.begin();
  while (1)
  {
    if (it->cod == cod)
    {
      it->qtd += qtd;
      break;
    }
    else
      it++;
  }
}

void Venda::efetuaVenda(int cod, int qtd)
{
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
  {
    std::list<Celular>::iterator it;
    it = m_celulares.begin();
    for (auto x : m_celulares)
    {
      if (x.cod == cod)
      {
        if (!(x.qtd < qtd))
        {
          it->qtd -= qtd;
        }
        break;
      }
      ++it;
    }
  }
}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto)
{
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it;
  for (it = this->m_celulares.begin(); it != this->m_celulares.end(); ++it)
  {
    if (it->fabricante == fabricante)
      it->valor -= it->valor * (desconto / 100);
  }
}

void Venda::removeModelo(int cod)
{
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it = m_celulares.begin();

  while (1)
  {
    if (it->cod == cod)
    {
      break;
    }
    it++;
  }
  m_celulares.erase(it);
}

void Venda::imprimeEstoque() const
{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
  for (const auto &celular : this->m_celulares)
  {
    std::cout << celular.fabricante;
    std::cout << " ";

    std::cout << celular.modelo;
    std::cout << ", ";

    std::cout << celular.armazenamento;
    std::cout << "GB, ";

    std::cout << celular.memoria;
    std::cout << "GB RAM, ";

    std::cout << (int)(celular.peso * 1000);
    std::cout << " gramas, ";

    std::string teste = "";
    teste += std::toupper(celular.cor[0]);
    teste += celular.cor.substr(1, celular.cor.size());

    std::cout << teste;
    std::cout << ", ";

    std::cout << celular.qtd;
    if (celular.qtd == 1)
      std::cout << " restante, ";
    else
      std::cout << " restantes, ";

    std::cout << "R$ ";
    std::cout << std::fixed << std::setprecision(2) << celular.valor;

    std::cout << std::endl;
  }
}