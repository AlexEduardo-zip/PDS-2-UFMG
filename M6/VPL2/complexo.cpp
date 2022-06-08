// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
  mod_ = sqrt(a * a + b * b);
  arg_ = atan2(b, a);
}

double Complexo::real() const {
  return mod_ * cos(arg_);
}

double Complexo::imag() const {
  return mod_ * sin(arg_);
}

bool Complexo::operator==(Complexo x) const {
  // Precisão numérica utilizda.    
  static const double epsilon = 1E-6;

  // Quando o módulo é zero, não importa o valor do argumento.
  if (mod_ < epsilon) {   
    return fabs(x.mod_ - mod_) < epsilon;
  } else {
    return fabs(x.mod_ - mod_) < epsilon &&
           fabs(sin(x.arg_) - sin(arg_)) < epsilon &&
           fabs(cos(x.arg_) - cos(arg_)) < epsilon;
  }
}

void Complexo::operator=(Complexo x) {
  mod_ = x.mod_;
  arg_ = x.arg_;
} 

double Complexo::modulo() const {
  return mod_;
}

Complexo Complexo::conjugado() const {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = -arg_;
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = arg_ + M_PI;
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  i.mod_ = 1.0 / mod_;
  i.arg_ = -arg_;
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  p.mod_ = mod_ * y.mod_;
  p.arg_ = arg_ + y.arg_;
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
