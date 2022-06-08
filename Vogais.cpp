#include <iostream>
#include <string>
using namespace std;
int main() 
{
    std::string palavra;
    std::cin >> palavra;
    char a = 'a';
    int na = 0;
    char e = 'e';
    int ne = 0;
    char i = 'i';
    int ni = 0;
    char o = 'o';
    int no = 0;
    char u = 'u';
    int nu = 0;
    for (int indice = 0; indice < palavra.size() ; indice++)
    {
        if (palavra[indice] == a)
        {
            na++;
            continue;
        }
         if (palavra[indice] == e)
        {
            ne++;
            continue;
        }
         if (palavra[indice] == i)
        {
            ni++;
            continue;
        }
         if (palavra[indice] == o)
        {
            no++;
            continue;
        }
         if (palavra[indice] == u)
        {
            nu++;
            continue;
        }
    }
    if (na != 0)
    {
        std::cout << "a ";
        std::cout << na;
        std::cout << endl;
    }
        if (ne != 0)
    {
        std::cout << "e ";
        std::cout << ne;
        std::cout << endl;
    }
        if (ni != 0)
    {
        std::cout << "i ";
        std::cout << ni;
        std::cout << endl;
    }
        if (no != 0)
    {
        std::cout << "o ";
        std::cout << no;
        std::cout << endl;
    }
        if (nu != 0)
    {
        std::cout << "u ";
        std::cout << nu;
        std::cout << endl;
    }
}
