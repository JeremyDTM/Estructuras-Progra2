#ifndef PAGINA_H
#define PAGINA_H
#include <string>
#include <iostream>

using namespace std;

class Pagina{
    public:
        Pagina();
        void Mostrar();
        string * getClaves();
        void annadirRamas(int posicion,Pagina *pagina);
        int getCuentas();
        void setCuentas(int pCuentas);
        void annadirClaves(int posicion,string valor);
    private:
        string claves[4];
        int max=4;
        int min=2;
        Pagina *ramas[5]={nullptr};
        int cuentas=0,factorBalance=0;
    friend class ArbolB;
};
typedef  Pagina *pPagina;

#endif // PAGINA_H
