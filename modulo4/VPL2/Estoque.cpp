#include "Estoque.hpp"

using namespace std;

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
  // TODO
  bool achou = 0;
  for (map<string, int>::iterator it = produto.begin(); it != produto.end(); it++)
  {
    if (it->first == mercadoria)
    {
      achou = 1;
      it->second = it->second + qtd;
    }
  }
  if (!achou)
  {
    this->produto.insert(pair<string, int>(mercadoria, qtd));
  }
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
  // TODO
  bool achou = 0;
  map<string, int>::iterator it;
  for (it = produto.begin(); it != produto.end(); it++)
  {
    if (mercadoria == it->first)
    {
      achou = 1;
      if (qtd > it->second)
        cout << it->first << "insuficiente" << endl;
      else
        it->second = it->second - qtd;
    }
  }
  if (!achou)
  {
    cout << it->first << "inexistente" << endl;
  }
}

unsigned int Estoque::get_qtd(const std::string &mercadoria) const
{
  // TODO
  map<string, int> C_produto = this->produto;
  bool achou = 0;
  for (map<string, int>::iterator it = C_produto.begin(); it != C_produto.end(); it++)
  {
    if (mercadoria == it->first)
    {
      achou = 1;
      return it->second;
    }
  }
  if (!(achou))
  {
    return 0;
  }
}

void Estoque::imprime_estoque() const
{
  // TODO
  vector<string> nomeProdutos;
  map<string, int> C_produto = this->produto;

  for (map<string, int>::iterator it = C_produto.begin(); it != C_produto.end(); it++)
  {
    nomeProdutos.push_back(it->first);
  }
  sort(nomeProdutos.begin(), nomeProdutos.end());

  for (int i = 0; i < nomeProdutos.size(); i++)
  {
    for (map<string, int>::iterator it = C_produto.begin(); it != C_produto.end(); ++it)
    {
      if (it->first == nomeProdutos[i])
      {
        std::cout << it->first << ", " << it->second << std::endl;
      }
    }
  }
}

Estoque &Estoque::operator+=(const Estoque &rhs)
{
  // TODO
  for (map<string, int>::const_iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
  {
    if (this->produto[it->first])
      this->produto[it->first] += it->second;
    else
      this->produto.insert(pair<string, int>(it->first, it->second));
  }
  return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs)
{
  // TODO
  for (map<string, int>::const_iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
  {
    for (map<string, int>::const_iterator c_it = rhs.produto.begin(); c_it != rhs.produto.end(); c_it++)
    {
      if (it->first == c_it->first)
      {
        sub_mercadoria(it->first, c_it->second);
      }
    }
  }
  return *this;
}

bool operator>(Estoque &lhs, Estoque &rhs)
{

  vector<string> nomeProdutosRHS;

  for (map<string, int>::iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
  {
    nomeProdutosRHS.push_back(it->first);
  }

  vector<string> nomeProdutosLHS;

  for (map<string, int>::iterator it = lhs.produto.begin(); it != lhs.produto.end(); it++)
  {
    nomeProdutosLHS.push_back(it->first);
  }

  if (nomeProdutosRHS.size() > nomeProdutosLHS.size())
  {
    return false;
  }

  // TODO
  for (map<string, int>::iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
  {
    if (it->second > lhs.get_qtd(it->first))
      return false;
  }
  return true;
}

bool operator<(Estoque &lhs, Estoque &rhs)
{
  {

    vector<string> nomeProdutosRHS;

    for (map<string, int>::iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
    {
      nomeProdutosRHS.push_back(it->first);
    }

    vector<string> nomeProdutosLHS;

    for (map<string, int>::iterator it = lhs.produto.begin(); it != lhs.produto.end(); it++)
    {
      nomeProdutosLHS.push_back(it->first);
    }

    if (nomeProdutosRHS.size() < nomeProdutosLHS.size())
    {
      return false;
    }

    // TODO
    for (map<string, int>::iterator it = rhs.produto.begin(); it != rhs.produto.end(); it++)
    {
      if (it->second > lhs.get_qtd(it->first))
        return false;
    }
    return true;
  }
}