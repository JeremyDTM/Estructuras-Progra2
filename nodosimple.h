#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H


#include "arbolavl.h"
#include "arbolb.h"
#include "arbolaa.h"


class nodoSimple{
    public:
        nodoSimple(int num,ArbolB* arbolB);
        nodoSimple(int num, AVL* arbolAVL);
    private:
        int valor;
        nodoSimple* siguiente;
        nodoSimple* anterior;
        ArbolB* abajo;
        AVL* abajo2;
    friend class listaSimple;
};

#endif NODOSIMPLE_H
