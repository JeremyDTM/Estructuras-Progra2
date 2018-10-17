#include "pagina.h"

Pagina::Pagina(){
}


int Pagina::getCuentas(){
    return cuentas;
}

void Pagina::setCuentas(int pCuentas){
    cuentas=pCuentas;
}

void Pagina::annadirClaves(int posicion,string valor){
    claves[posicion]=valor;
}

void Pagina::annadirRamas(int posicion,Pagina *pagina){
    ramas[posicion]=pagina;
}
