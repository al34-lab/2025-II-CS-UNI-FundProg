#include <iostream>
#include <fstream>
#include "academic.h"

void PrintPeople(CPerson *pPerson){
    cout << pPerson->ToString() << std::endl;
}

void PrintPeopleObject(CPerson &rPerson){
    PrintPeople(&rPerson);
}

void DemoAcademic(){
    CPerson    pe(100, "Ernesto");

    CStudent   s1(543, "Xingbeck", "CS");
    s1.SetCode(777);

    CProfessor p1(222, "Juan Jose", 1000);
    p1.SetName("Sandro");
    p1.SetSalary(10000);

    std::cout << pe.ToString() << std::endl;
    std::cout << p1.ToString() << std::endl;
    std::cout << s1.ToString() << std::endl;

    ofstream of("personal.txt");
    of << pe.ToString() << std::endl << "==========\n"
       << p1.ToString() << std::endl << "==========\n"
       << s1.ToString() << std::endl;

    std::cout << "Imprimiendo con Polimorfismo (Parte 1)"  << std::endl;
    CPerson *pPeople[] = {&pe, &s1, &p1};
    for(auto i = 0 ; i < 3 ; ++i)
        PrintPeople(pPeople[i]);

    std::cout << "Imprimiendo con Polimorfismo (Parte 2)"  << std::endl;
    for(auto i = 0 ; i < 3 ; ++i)
        PrintPeopleObject(*pPeople[i]);
}