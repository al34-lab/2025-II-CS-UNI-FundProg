
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

    std::string ToString(){
        std::stringstream stream;
    
        stream << "Student: " << std::endl;
        // Comun
        stream << CPerson::ToString();
        // Specifica
        stream << "School: " << GetSchool() << std::endl;
        
        return stream.str();
    }
};


#endif // __ALUMNO_H__