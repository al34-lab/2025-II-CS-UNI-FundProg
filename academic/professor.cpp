#include "professor.h"

CProfessor::CProfessor(CodeType code,
                       std::string name,
                       SalaryType salary)
          : CPerson(code, name), m_salary(salary)
{

}