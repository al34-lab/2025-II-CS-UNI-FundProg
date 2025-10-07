
#include "MoveObject.h"

void DemoMoveConstructor(){
    X obj1("Juan");
    obj1.SetExtraField(5, 10);
    obj1.PrintExtraField();

    X obj2(std::move(obj1));
    std::cout << "Printing obj2:" << std::endl;
    obj2.PrintExtraField();
    std::cout << "Printing obj1:" << std::endl;
    obj1.PrintExtraField();
    std::cout << "End of DemoMoveConstructor" << std::endl;
}