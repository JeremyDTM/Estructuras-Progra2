#include "nodosimple.h"

nodoSimple::nodoSimple(int num, ArbolB* arbolB){
    valor=num;
    abajo=arbolB;
}

nodoSimple::nodoSimple(int num, AVL* arbolAVL){
    valor=num;
    abajo2=arbolAVL;
}
