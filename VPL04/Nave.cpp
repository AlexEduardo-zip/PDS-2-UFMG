#include "Nave.hpp"
#include <iostream>

Nave::Nave(Ponto2D p1, double forca)
{
    this->_p1 = p1;
    this->_forca = forca;
    this->_energia = 100;
}

void Nave::mover(double dx, double dy)
{
    this->_p1._x = _p1._x + dx;
    this->_p1._y = _p1._y + dy;
}

double Nave::calcular_distancia(Nave *nave)
{
    double distancia = this->_p1.calcular_distancia(&nave->_p1);
    return distancia;
}

Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    int menor = 10;
    int j = 0;
    double dist_aux = 0.0;
    for (j = 0; j < n; j++)
    {
        dist_aux = this->_p1.calcular_distancia(&naves[j]->_p1);
        if (dist_aux > 0.0)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {

        double menor_dist = this->_p1.calcular_distancia(&naves[i]->_p1);

        if (menor_dist < dist_aux && menor_dist > 0.0)
        {
            menor = i;
        }
        else
        {
            menor = j;
        }
    }
    return naves[menor];
}

void Nave::atacar(Nave **naves, int n)
{
    Nave *vitima = this->determinar_nave_mais_proxima(naves, n);
    //std::cout << "this " << this->_p1._x << " " << this->_p1._y << std::endl;
    //std::cout << "vitima " << vitima->_p1._x << " " << vitima->_p1._y << std::endl;
    double dist = this->_p1.calcular_distancia(&vitima->_p1);
    //std::cout << "distancia " << dist << std::endl;
    double forca = this->_forca;
    //std::cout << "força " << forca << std::endl;
    //std::cout << "energia 1 " << vitima->_energia << std::endl;
    double ataque = (100.0 / dist) * forca;
    if (ataque > 30)
    {
        vitima->_energia -= 30;
    }
    else
    {
        vitima->_energia = vitima->_energia - ataque;
    }

    //std::cout << "energia 2" << vitima->_energia << std::endl;
    if (vitima->_energia <= 50.0)
    {
        std::cout << "Energia baixa!" << std::endl;
    }
}

void Nave::imprimir_status()
{
    std::cout << this->_p1._x << " " << this->_p1._y << " " << this->_energia << std::endl;
}