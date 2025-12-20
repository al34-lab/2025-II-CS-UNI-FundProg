#ifndef __MIVECTOR_H__
#define __MIVECTOR_H__

#include <iostream>
#include <stdexcept> //out_of_range

template <typename T>
class Mivector{
private: 
    T* datos;
    int capacidad;
    int cantidad;
    void redimensionar(){
        int nuevacap = (capacidad==0) ? 1: capacidad*2;
        T* nuevosDatos = new T[nuevacap];
        for(int i=0; i<cantidad; i++){
            nuevosDatos[i] = datos[i];
        }

        delete[] datos;
        datos = nuevosDatos;
        capacidad = nuevacap;
    }
public:
    Mivector(){
        capacidad = 2;
        cantidad = 0;
        datos = new T[capacidad];
    }

    ~Mivector(){
        delete[] datos;
    }

    //constructor de copia: Mivector A = B
    Mivector(const Mivector& otro){
        capacidad = otro.capacidad;
        cantidad = otro.cantidad;
        datos = new T[capacidad];
        
        for(int i=0; i<cantidad; i++){
            datos[i] = otro.datos[i];
        }
    }

    //operador de asignacion: A = B (cuando ambos ya existen)
    Mivector& operator=(const Mivector& otro){
        if(this != &otro){
            delete[] datos;
            capacidad = otro.capacidad;
            cantidad = otro.cantidad;
            datos = new T[capacidad];

            for(int i=0; i<cantidad; i++){
                datos[i] = otro.datos[i];
            }
        }
        return *this;
    }

    void push_back(T valor){
        if(cantidad == capacidad){
            redimensionar();
        }
        datos[cantidad]=valor;
        cantidad++;
    }

    int size() const{
        return cantidad;   
    }

    //lectura y escritura: (v[0]=5)
    T& operator[](int index){
        if(index<0||index >= cantidad){
            throw std::out_of_range("Indice fuera de rango");
        }
        return datos[index];
    }
    //version del operador solo lectura
    const T& operator[] (int index) const{
        if(index<0||index >= cantidad){
            throw std::out_of_range("Indice fuera de rango");
        }
        return datos[index];
    }
    
};
#endif 