#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include "general/types.h"

class CComplex
{private:
    // Atributos (Variables)
    RealType m_r;
    ImagType m_i;
    // Metodos privados

 public:
    // Atributos publicos

    // Metodos publicos
    void SetReal(RealType r) { m_r = r;     }
    RealType GetReal()       { return m_r;  }

    void SetImag(ImagType i) { m_i = i;     }
    ImagType GetImag()       { return m_i;  }

    // Prueba
    int MethodX(int n);
};

void DemoComplex();

#endif // __COMPLEX_H__