#include <iostream>
#include <fstream>
#include "academic.h"

void DemoAcademic(){
    CStudent   s1(543, "Xingbeck", "CS");
    s1.SetCode(777);

    CProfessor p1(222, "Juan Jose", 1000);
    p1.SetName("Sandro");
    p1.SetSalary(10000);

    std::cout << p1.ToString() << std::endl;
    std::cout << s1.ToString() << std::endl;

    ofstream of("personal.txt");
    of << p1.ToString() << std::endl << "==========\n"
       << s1.ToString() << std::endl;
}