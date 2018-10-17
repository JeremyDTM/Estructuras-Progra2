#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <math.h>
#include "nodousuario.h"
#include <stdio.h>
using namespace std;


class AVL{
    public:
        pNodoUsuario raiz;
        pNodoUsuario actual;
        AVL():raiz(NULL){}
        void InsertaNodo(int num);
        bool Hh;
        void PreordenR(NodoUsuario* R);
        void InordenR(NodoUsuario* R);
        void PostordenR(NodoUsuario* R);
        void Borrar(NodoUsuario *nodoB, bool);
        void BorrarBalanceado(NodoUsuario *r, bool, int eliminar);
        void Equilibrar1(NodoUsuario *n, bool);
        void Equilibrar2(NodoUsuario *n, bool);
        void cargarArch(ifstream& arch);
        void Insertar(NodoUsuario *r, bool, string ciudad, int x, string nombre, string telefono, pNodoUsuario pPadre);
        pNodoUsuario RotacionDobleIzquierda(NodoUsuario *n1, NodoUsuario *n2);
        pNodoUsuario RotacionDobleDerecha(NodoUsuario *n1, NodoUsuario *n2);
        pNodoUsuario RotacionSimpleIzquierda(NodoUsuario *n1, NodoUsuario *n2);
        pNodoUsuario RotacionSimpleDerecha(NodoUsuario *n1, NodoUsuario *n2);

};
