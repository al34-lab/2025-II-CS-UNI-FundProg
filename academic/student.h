#ifndef __ALUMNO_H__
#define __ALUMNO_H__
#include <string>
#include "../general/types.h"

// namespace Academic{

class CStudent{
private:
    CodeType      m_code;
    std::string   m_name;
public:
    void     SetCode(CodeType code) { m_code = code;    }
    CodeType GetCode()              { return m_code;    }

    void        SetName(std::string name) { m_name = name;    }
    std::string GetName()                 { return m_name;    }
};


#endif // __ALUMNO_H__