#ifndef __MOVEOBJECT_H__
#define __MOVEOBJECT_H__
#include <iostream>
#include <string>

class X{
private:
    int *m_ExtraField = nullptr;
    int  m_nElements = 0;
    std::string m_name;
public:
    X(std::string name) : m_name(name), m_ExtraField(nullptr), m_nElements(0) {}
    X(int nElements, int val){
        SetExtraField(nElements, val);
    }
    X(X &&other) : m_name      (std::move(other.m_name)),
                   m_nElements (std::exchange(other.m_nElements, 0)),
                   m_ExtraField(std::exchange(other.m_ExtraField, nullptr))
    { 
        std::cout << "Move Constructor called for " << m_name << std::endl;
    }
    ~X(){
        std::cout << "Destructor called for " << m_name << "(" << m_nElements << ")" << std::endl;
        delete [] m_ExtraField;
    }

    void SetExtraField(int nElements, int val) {
        m_nElements = nElements;
        delete [] m_ExtraField;
        m_ExtraField = new int[nElements];
        std::fill_n(m_ExtraField, nElements, val);
    }
    void PrintExtraField() {
        if(m_ExtraField == nullptr){
            std::cout << "ExtraField is nullptr" << std::endl;
            return;
        }
        for(auto i = 0 ; i < m_nElements ; ++i)
            std::cout << m_ExtraField[i] << " ";
        std::cout << std::endl;
    }
};

void DemoMoveConstructor();

#endif // __MOVEOBJECT_H__