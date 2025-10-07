
#include <iostream>
#include "complex.h"
#include "MoveObject.h"

// Operadores
CComplex& CComplex::operator=(CComplex c) {
    m_r = c.GetReal();
    m_i = c.GetImag();
    return *this;
}

CComplex CComplex::operator+(CComplex &c) {
    return CComplex(GetReal() + c.GetReal(), GetImag() + c.GetImag());
}

CComplex& CComplex::operator+=(CComplex &c) {
    *this = *this + c;
    return *this;
}

CComplex CComplex::operator-(CComplex &c) {
    return CComplex(GetReal() - c.GetReal(), GetImag() - c.GetImag());
}

CComplex& CComplex::operator-=(CComplex &c) {
    m_r -= c.GetReal();
    m_i -= c.GetImag();
    return *this;
}

CComplex CComplex::operator*(CComplex &c) {
    return CComplex(GetReal() * c.GetReal() - GetImag() * c.GetImag(), 
                    GetReal() * c.GetImag() + GetImag() * c.GetReal());
}

CComplex CComplex::operator/(CComplex &c) {
    RealType denom = c.GetReal() * c.GetReal() + c.GetImag() * c.GetImag();
    return CComplex((GetReal() * c.GetReal() + GetImag() * c.GetImag()) / denom,
                    (GetImag() * c.GetReal() - GetReal() * c.GetImag()) / denom);
}