
#ifndef __ALUMNO_H__
#define __ALUMNO_H__
#include <sstream>
#include <string>
#include "../general/types.h"

// namespace Academic{

class CStudent{
private:
    CodeType      m_code;
    std::string   m_name;
    std::string   m_school;
public:
    CStudent(CodeType code, std::string name, std::string school);
    void     SetCode(CodeType code) { m_code = code;    }
    CodeType GetCode()              { return m_code;    }

    void        SetName(std::string name) { m_name = name;    }
    std::string GetName()                 { return m_name;    }

    void        SetSchool(std::string school){ m_school = school;    }
    std::string GetSchool()                 { return m_school;    }

    std::string ToString(){
        std::stringstream stream;
    
        stream << "Student: " << std::endl;
        // Comun
        stream << "Name  : " << GetName() << ", " << std::endl
               << "Codigo: " << GetCode() << ", " << std::endl;
        // Specifica
        stream << "School: " << GetSchool() << std::endl;
        
        return stream.str();
    }
};


#endif // __ALUMNO_H__