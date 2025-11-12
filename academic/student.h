
#ifndef __ALUMNO_H__
#define __ALUMNO_H__
#include "person.h"

// namespace Academic{

class CStudent : public CPerson{
private:
    std::string   m_school;
public:
    CStudent(CodeType code, std::string name, std::string school);

    void        SetSchool(std::string school){ m_school = school;    }
    std::string GetSchool()                 { return m_school;    }

    std::string ToString() override {
        std::stringstream stream;
        stream << "Student: " << std::endl
               << CPerson::ToString()       // Comun
               << "School: " << GetSchool() // Specifica
               << std::endl;
        return stream.str();
    }
};

#endif // __ALUMNO_H__