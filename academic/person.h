#ifndef __PERSON_H__
#define __PERSON_H__
#include <sstream>
#include <string>
#include "../general/types.h"

class CPerson{
private:
    CodeType      m_code;
    std::string   m_name;

public:
    CPerson(CodeType code, std::string name);
    void     SetCode(CodeType code) { m_code = code;    }
    CodeType GetCode()              { return m_code;    }

    void        SetName(std::string name) { m_name = name;    }
    std::string GetName()                 { return m_name;    }

    virtual std::string ToString(){
        std::stringstream stream;
    
        // Comun
        stream << "XName  : " << GetName() << ", " << std::endl
               << "XCodigo: " << GetCode() << ", " << std::endl;
        
        return stream.str();
    }
};

#endif // __PERSON_H__