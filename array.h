#ifndef __ARRAYS_H__
#define __ARRAYS_H__
#include <iostream>
#include "general/types.h"
using namespace std;

template <typename T>
void PrintArray(T *pArray, size_t n, ostream &os){
    for(size_t i = 0 ; i < n ; ++i)
        os << pArray[i] << " ";
    os << endl;
}
// TODO: pasar estas 3 funciones a templates
void CreateArray(ContainerElemType *&pArray, size_t n);
void ReadArray(ContainerElemType *pArray, size_t n);
void DestroyArray(ContainerElemType *&pArray);

void DemoArrays();

#endif // __ARRAYS_H__