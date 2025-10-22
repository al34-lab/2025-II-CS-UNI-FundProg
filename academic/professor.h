#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__
#include <sstream>
#include <string>
#include "../general/types.h"

class CProfessor{
private:
    CodeType      m_code;
    std::string   m_name;
    SalaryType    m_salary;

public:
    CProfessor(CodeType code, std::string name, SalaryType salary);
    void     SetCode(CodeType code) { m_code = code;    }
    CodeType GetCode()              { return m_code;    }

    void        SetName(std::string name) { m_name = name;    }
    std::string GetName()                 { return m_name;    }

    void       SetSalary(SalaryType salary){ m_salary = salary; }
    SalaryType GetSalary()                 { return m_salary;   }

    std::string ToString(){
        std::stringstream stream;
    
        stream << "Professor: " << std::endl;
        // Comun
        stream << "Name  : " << GetName() << ", " << std::endl
               << "Codigo: " << GetCode() << ", " << std::endl;
        // Specifica
        stream << "Salary: " << GetSalary() << std::endl;
        
        return stream.str();
    }
};

#endif // __PROFESSOR_H__