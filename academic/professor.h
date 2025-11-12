#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__
#include "person.h"

class CProfessor : public CPerson
{
private:
    SalaryType    m_salary;

public:
    CProfessor(CodeType code, std::string name, SalaryType salary);

    void       SetSalary(SalaryType salary){ m_salary = salary; }
    SalaryType GetSalary()                 { return m_salary;   }

    std::string ToString() override {
        std::stringstream stream;
    
        stream << "Professor: " << std::endl
               << CPerson::ToString()       // Comun
               << "Salary: " << GetSalary() // Specifica
               << std::endl;
        return stream.str();
    }
};

#endif // __PROFESSOR_H__