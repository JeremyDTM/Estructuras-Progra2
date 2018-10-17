#ifndef _NODOAA_H
#define	_NODOAA_H

#include <iostream>
using namespace std;


class nodoAA {
   public:
    nodoAA(string v)
    {
       valor = v;
       siguiente = nullptr;
       anterior = nullptr;
       Hizq = nullptr;
       Hder = nullptr;
    }
    void InsertarNodoAA(string num);
    int largo(nodoAA *);

   private:
        string valor;
        nodoAA *siguiente;
        nodoAA *anterior;
        nodoAA *Hizq;
        nodoAA *Hder;
   friend class ArbolAA;
};

typedef nodoAA *pnodoAA;

#endif // _NODOAA_H
