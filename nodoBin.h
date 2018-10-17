#ifndef NODOBIN_H
#define	NODOBIN_H

#include <iostream>
using namespace std;


class nodoBin{
   public:
    nodoBin(string v);
    void InsertarB(string x);
    void Mostrar();
    bool BuscarCiudad(string& ciudad,bool& esta);
   private:
    int codCiudad;
    string nombre;
    nodoBin *Hizq;
    nodoBin *Hder;


   friend class arbolBin;
};

typedef nodoBin *pnodoBin;

#endif NODOBIN_H
