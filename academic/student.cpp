#include "student.h"

CStudent::CStudent(CodeType    code, 
                   std::string name,
                   std::string school)
        : CPerson(code, name), m_school(school)
{

}