#include <stdlib.h>
#include <iostream>

#include "arbolaa.h"
#include "nodoaa.h"

using namespace std;


pnodoAA insertar(string num, nodoAA *arbolAA){
    cout<<num<<endl;
    if(arbolAA == nullptr){
        arbolAA = new nodoAA(num);
        return arbolAA;
    }
    else if(num <= arbolAA->valor){
        arbolAA->Hizq = insertar(num,arbolAA->Hizq);
    }
    else if(num > arbolAA->valor){
        arbolAA->Hder = insertar(num,arbolAA->Hder);
    }
    cout<<"C"<<endl;
    arbolAA = torsion(arbolAA);
    cout<<"D"<<endl;
    arbolAA = division(arbolAA);
    cout<<"E"<<endl;
    cout<<arbolAA->valor<<endl;
    return arbolAA;
}

void InordenR(nodoAA *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<" - ";
        InordenR(R->Hder);
    }
}

pnodoAA torsion(nodoAA *T){
    if(T == NULL){
        cout<<"Aqui entro porque era null"<<endl;
        return NULL;
    }
    else if(T->Hizq == NULL){
        cout<<"Aqui entro porque hizq era null"<<endl;
        return T;
    }
    else if(T->Hizq->nivel == T->nivel){
        cout<<"Aqui entro porque hizq era del mismo nivel"<<endl;
        pnodoAA L;
        L = T->Hizq;
        T->Hizq = L->Hder;
        L->Hder = T;
        return L;
    }
    else{
        cout<<"Aqui entro porque no se cumple ninguna de las anteriores"<<endl;
        return T;
    }
}

pnodoAA division(nodoAA *T){
    if(T == NULL){
        cout<<"Aqui entro porque era null(division)"<<endl;
        return NULL;
    }
    else if(T->Hder == NULL){
        cout<<"Aqui entro porque hder era null(division)"<<endl;
        return T;
    }
    else if(T->Hder->Hder == NULL){
        cout<<"Aqui entro porque hder->hder era null(division)"<<endl;
        return T;
    }
    else if(T->nivel == T->Hder->Hder->nivel){
        cout<<"Aqui entro porque hder->hder tiene el mismo nivel(division)"<<endl;
        pnodoAA R;
        R = T->Hder;
        T->Hder = R->Hizq;
        R->Hizq = T;
        R->nivel = R->nivel + 1;
        return R;
    }
    else{
        return T;
    }
}


void ArbolAA::InsertaNodo(string num){
    if(raiz==NULL){
        raiz = new nodoAA(num);
    }else{
        raiz->InsertarNodoAA(num);
    }
}

void nodoAA::InsertarNodoAA(string num){
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new nodoAA(num);
        }else{
            Hizq->InsertarNodoAA(num);
            //Aqui deberia ir el metodo torsion
        }
    }else{
        if(Hder==NULL){
            Hder = new nodoAA(num);
        }else{
            Hder->InsertarNodoAA(num);
            //Aqui deberia ir el metodo division
        }
    }
}
