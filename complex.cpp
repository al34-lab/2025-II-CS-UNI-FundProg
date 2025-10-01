
#include <iostream>
#include "complex.h"

int CComplex::MethodX(int n)
{   return n+1;     }

void DemoComplex(){
    CComplex c1, c2, c3;
    c1.SetReal(3);
    c1.SetImag(4);

    RealType r = c1.GetReal();
    ImagType i = c1.GetImag();
    std::cout << "Real: " << r << " Imag: " << i << std::endl;

    CComplex *pC = nullptr;
    pC = new CComplex[3];
    for(auto i = 0 ; i < 3 ; ++i){
        pC[i].SetReal(i);
        pC[i].SetImag(i+5);
    }
    
    for(auto i = 0 ; i < 3 ; ++i)
        std::cout << "Complex[" << i << "] "
                  << " Real: " << pC[i].GetReal()
                  << " Imag: " << pC[i].GetImag() << std::endl;
    delete [] pC;
}