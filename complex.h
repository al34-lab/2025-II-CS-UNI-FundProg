#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include "general/types.h"

class CComplex
{private:
    // Atributos (Variables)
    RealType m_r = 0;
    ImagType m_i = 0;

    // Metodos privados
 public:
    // Constructores
    // Caracteristicas de un constructor:
    // 1. Tiene el mismo nombre que la clase
    // 2. No tiene tipo de retorno (ni siquiera void)
    // 3. Se llama automaticamente al crear un objeto de la clase
    // 4. Puede tener parametros (como una funcion)
    // 5. Puede tener valores por defecto en los parametros
    // 6. Puede haber mas de un constructor (sobrecarga de constructores)
    // 7. Si no se define ningun constructor, el compilador crea uno por defecto
    // 8. Si se define al menos un constructor, el compilador NO crea uno
    // 9. Un constructor puede llamar a otro constructor (delegacion de constructores)
    // 10. Un constructor puede tener una lista de inicializacion (recomendado)
    // 11. Un constructor puede ser declarado como explicit (para evitar conversiones implicitas)
    // CComplex() : m_r(0), m_i(0) {}
    CComplex() : CComplex(0,0) {}
    CComplex(RealType r, ImagType i) : m_r(r), m_i(i) {}
    
    CComplex(CComplex &c) : CComplex(c.m_r, c.m_i)    {}

    // Caracteristicas de un Destructor:
    // 1. Tiene el mismo nombre que la clase, pero con un ~ al inicio
    // 2. No tiene tipo de retorno (ni siquiera void)
    // 3. No tiene parametros
    // 4. Se llama automaticamente en el delete (para objetos dinamicos) o
    //.   cuando el objeto sale de las {} donde fue declarado (para objetos estaticos)
    // 5. Solo puede haber un destructor
    // 6. Si no se define un destructor, el compilador crea uno {} por defecto
    // 7. Si se define un destructor, el compilador NO crea uno
    // 8. Es recomendable que sea virtual
    // 9. No puede ser declarado como explicit
    // 10. No puede tener una lista de inicializacion
    // 11. No puede llamar a otro destructor
    virtual ~CComplex() {
        std::cout << "Destructor called for Complex(" 
                  << m_r << ", " << m_i << ")" << std::endl;
    } // Destructor

    // Atributos publicos

    // Metodos publicos
    void SetReal(RealType r) { m_r = r;     }
    RealType GetReal()       { return m_r;  }

    void SetImag(ImagType i) { m_i = i;     }
    ImagType GetImag()       { return m_i;  }

    // Operadores
    CComplex& operator=(CComplex &c);

    CComplex operator+(CComplex &c);
    CComplex& operator+=(CComplex &c);

    CComplex operator-(CComplex &c);
    CComplex& operator-=(CComplex &c);

    CComplex operator*(CComplex &c);
    CComplex operator/(CComplex &c);
};

void DemoComplex();

#endif // __COMPLEX_H__