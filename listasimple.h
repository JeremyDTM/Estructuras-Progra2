#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodosimple.h"
#include "arbolbin.h"

class listaSimple
{
    public:
        listaSimple();
        void Insertar(int num, ArbolB* arbolB);
        void Insertar(int num, AVL* arbolAVL);
        void users(arbolBin arbolBin);
        void Mostrar();
    private:
        nodoSimple* primero=nullptr;

};

#endif // LISTASIMPLE_H
