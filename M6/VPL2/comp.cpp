// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo()
{
    real_ = 0.0;
    imag_ = 0.0;
}

Complexo::Complexo(double a)
{
    real_ = a;
    imag_ = 0.0;
}

Complexo::Complexo(double a, double b)
{
    real_ = a;
    imag_ = b;
}

double Complexo::real() const
{
    return real_;
}

double Complexo::imag() const
{
    return imag_;
}

bool Complexo::operator==(Complexo x) const
{
    if (real_ == x.real_ && imag_ == x.imag_)
        return 1;
    else
        return 0;
}

void Complexo::operator=(Complexo x)
{
    imag_ = x.imag_;
    real_ = x.real_;

    return;
}

double Complexo::modulo() const
{
    return sqrt(pow(real_, 2) + pow(imag_, 2));
}

Complexo Complexo::conjugado() const
{
    Complexo conjugado(real_, -imag_);
    return conjugado;
}

Complexo Complexo::operator-() const
{
    Complexo c;
    c.real_ = -real_;
    c.imag_ = -imag_;
    return c;
}

Complexo Complexo::inverso() const
{
    Complexo i(real_ / ((pow(real_, 2)) + (pow(imag_, 2))), -imag_ / ((pow(real_, 2)) + (pow(imag_, 2))));
    return i;
}

Complexo Complexo::operator+(Complexo y) const
{
    Complexo s(real_ + y.real_, (imag_ + y.imag_));
    return s;
}

Complexo Complexo::operator-(Complexo y) const
{
    return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const
{
    Complexo p;
    p.real_ = real_ * y.real_ - imag_ * y.imag_;
    p.imag_ = real_ * y.imag_ + imag_ * y.real_;
    return p;
}

Complexo Complexo::operator/(Complexo y) const
{
    Complexo aux;
    aux.real_ = (real_ * y.real_ + imag_ * y.imag_) / (y.real_ * y.real_ + y.imag_ * y.imag_);
    aux.imag_ = (imag_ * y.real_ - real_ * y.imag_) / (y.real_ * y.real_ + y.imag_ * y.imag_);
    return aux;
}