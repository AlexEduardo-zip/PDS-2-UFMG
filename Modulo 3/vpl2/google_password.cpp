#include "google_password.hpp"

#include <iostream>

using namespace std;

void GooglePassword::insert(const std::string &url,
                            const std::string &login,
                            const std::string &password)
{
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
  if (checkPassword(password))
  {
    Usuario user = Usuario(login, password);
    this->m_passwords.insert(std::pair<std::string, Usuario>(url, user));
  }
}

void GooglePassword::remove(const std::string &url)
{
  // TODO: Implemente este metodo
  std::map<std::string, Usuario>::iterator it = this->m_passwords.find(url);

  if (it == this->m_passwords.end())
    return;

  this->m_passwords.erase(it);
}

void GooglePassword::update(const std::string &url,
                            const std::string &login,
                            const std::string &old_password,
                            const std::string &new_password)
{
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
  std::map<std::string, Usuario>::iterator it = this->m_passwords.find(url);
  if (it == this->m_passwords.end())
    return;

  if (it->second.getPassword() != old_password)
    return;

  if (!checkPassword(new_password))
    return;

  it->second.setLogin(login);
  it->second.setPassword(new_password);
}

void GooglePassword::printPasswords()
{
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
  cout << this->m_passwords.size() << endl;

  std::map<std::string, Usuario>::iterator it;
  for (it = this->m_passwords.begin(); it != this->m_passwords.end(); it++)
  {
    cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << endl;
  }
}

bool GooglePassword::checkPassword(const std::string &password) const
{
  // TODO: Implemente este metodo
  if (password.size() <= 5 || password.size() >= 51)
    return false;

  if (password.find("123456") != std::string::npos)
    return false;

  if (password.find(" ") != std::string::npos)
    return false;

  return true;
}
