#ifndef ARBOLB_H
#define ARBOLB_H
#include "pagina.h"


class ArbolB{
    public:
        ArbolB();
        bool ArbolVacio(pPagina pRaiz);
        void InsertarValor(string pValor);
        void Empujar(string& pValor,pPagina& pRaiz,bool& EA,string& mdna,pPagina& X);
        void MostrarRaiz();
        void BuscarNodo(string& pValor,pPagina& pRaiz,bool& esta,int& k);
        void MeterHoja(string& pValor,pPagina& x,pPagina& pRaiz,int& k);
        void DividirNodo(string& pValor,pPagina Xder,pPagina& pRaiz,int& k,string& mda,pPagina& mder);
    private:
        pPagina raiz=new Pagina();
};

#endif // ARBOLB_H
