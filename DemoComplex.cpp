
#include <iostream>
#include "complex.h"

void Print(CComplex &c){
    std::cout << "Real: " << c.GetReal() << " Imag: " << c.GetImag() << std::endl;
}
void DemoComplex(){
    CComplex c1, c2(5, 6), c3, c4(c2), c5, c6;
    c1.SetReal(3);
    c1.SetImag(4);

    RealType r = c1.GetReal();
    ImagType i = c1.GetImag();
    std::cout << "Real: " << r << " Imag: " << i << std::endl;

    { CComplex c4(9,10);

    }

    c3 = c1 + c2;   // Operator +
    Print(c3);
    c5 = c1;        // Operator =
    Print(c5);
    c5 = c1 * c2;   // Operator *
    Print(c5);
    c6 = c1 - c2;   // Operator -
    Print(c6);
    c6 = c1 / c2;   // Operator /
    Print(c6);
    c6 += c1;          // Operator +=
    Print(c6);
    c6 -= c1;          // Operator -=
    Print(c6);
    c6 *= c1;          // Operator *=
    Print(c6);
    c6 /= c1;          // Operator /=
    Print(c6);
    if( c1 == c2)    // Operator ==
        std::cout << "c1 es igual a c2" << std::endl;
    if( c1 != c2)   // Operator !=
        std::cout << "c1 es diferente a c2" << std::endl;
        
    std::cout << c6 << "Hola" << i << std::endl; // Operator <<

    // p1 = (p2 * p3)/p4;

    CComplex *pC = nullptr;
    // Construyendo un arreglo dinamico de 3 complejos y 
    // llamando a sus constructores
    pC = new CComplex[3] { {0, 1}, {3,5}, {6,8} };
    for(auto i = 0 ; i < 3 ; ++i)
        std::cout << "Complex[" << i << "] "
                  << " Real: " << pC[i].GetReal()
                  << " Imag: " << pC[i].GetImag() << std::endl;
    delete [] pC;
    std::cout << "Ya casi voy saliendo" << std::endl;


}