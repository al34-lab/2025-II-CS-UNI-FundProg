#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__
#include "../general/types.h"

class CProfessor{
private:
    CodeType      m_code;
    std::string   m_name;
    SalaryType    m_salary;

public:
    void     SetCode(CodeType code) { m_code = code;    }
    CodeType GetCode()              { return m_code;    }

    void        SetName(std::string name) { m_name = name;    }
    std::string GetName()                 { return m_name;    }

    void       SetSalary(SalaryType salary){ m_salary = salary; }
    SalaryType GetSalary()                 { return m_salary;   }
};

#endif // __PROFESSOR_H__