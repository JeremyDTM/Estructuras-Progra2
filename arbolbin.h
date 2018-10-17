#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include "nodobin.h"
#include <string>
#include <iostream>

using namespace std;

class arbolBin
{
    public:
        arbolBin();
        void leerCiudad();
        void Insertar(string x);
        void Mostrar();
        bool BuscarCiudad(string ciudad);
    private:
        pnodoBin raiz=nullptr;

};

#endif // ARBOLBIN_H
