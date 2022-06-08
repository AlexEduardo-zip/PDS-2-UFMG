#include "fila.h"

struct No
{
  int chave;
  No *proximo;
};

Fila::Fila()
{
  // TODO
  this->primeiro_ = nullptr;
  this->ultimo_ = nullptr;
}

void Fila::Inserir(int k)
{
  // TODO
  No *novo_no = new No;
  novo_no->chave = k;

  if (this->primeiro_ == nullptr)
  {
    this->primeiro_ = novo_no;
    this->ultimo_ = novo_no;
  }
  else
  {
    this->ultimo_->proximo = novo_no;
    this->ultimo_ = novo_no;
  }
}

void Fila::RemoverPrimeiro()
{
  // TODO
  if (!(this->primeiro_ == nullptr))
  {
    // se houver só 1 elemento
    if (primeiro_->proximo == nullptr)
    {
      primeiro_ = nullptr;
      ultimo_ = nullptr;
    }
    else
      this->primeiro_ = this->primeiro_->proximo;
  }
  else
    throw ExcecaoFilaVazia();
}

int Fila::primeiro() const
{
  // TODO
  if (!(this->primeiro_ == nullptr))
  {
    return this->primeiro_->chave;
  }
  else
    throw ExcecaoFilaVazia();
}

int Fila::ultimo() const
{
  // TODO
  if (!(this->primeiro_ == nullptr))
  {
    return this->ultimo_->chave;
  }
  else
    throw ExcecaoFilaVazia();
}

int Fila::tamanho() const
{
  // TODO
  if (this->primeiro_ == nullptr) // se for vazia, entã retorna 0
    return 0;

  if (this->primeiro_ == this->ultimo_)
    return 1;

  No *aux = this->primeiro_;
  int tam = 0;
  // percorre a lista
  do
  {
    aux = aux->proximo;
    tam++;
  } while (aux);

  return tam;
}