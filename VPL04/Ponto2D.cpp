#include "Ponto2D.hpp"

Ponto2D::Ponto2D(){
    
}

Ponto2D::Ponto2D(double x, double y){
    this->_x = x;
    this->_y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto) {
    return sqrt(pow(ponto->_x - this->_x, 2) + pow(ponto->_y - this->_y, 2));
}