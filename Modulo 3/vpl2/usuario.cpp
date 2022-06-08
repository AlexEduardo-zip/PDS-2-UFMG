#include "usuario.hpp"

Usuario::Usuario(const std::string &login, const std::string &password)
{
  // TODO: Implemente este metodo
  this->m_login = login;
  this->m_password = password;
}

std::string Usuario::getLogin() const
{
  // TODO: Implemente este metodo
  return this->m_login;
}

std::string Usuario::getPassword() const
{
  // TODO: Implemente este metodo
  return this->m_password;
}

void Usuario::setPassword(const std::string &password)
{
  // TODO: Implemente este metodo
  this->m_password = password;
}

void Usuario::setLogin(const std::string &login)
{
  // TODO: Implemente este metodo
  this->m_login = login;
}