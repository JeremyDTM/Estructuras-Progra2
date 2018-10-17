#include "arbolb.h"
#include <iostream>
#include "pagina.h"
#include <string>

using namespace std;

ArbolB::ArbolB(){
}

bool ArbolB::ArbolVacio(pPagina pRaiz){
    bool vacio=true;
    if(pRaiz->getCuentas()!=0){
        return vacio=false;
    }else{
        return vacio;
    }
}




void ArbolB::MostrarRaiz(){
    raiz->Mostrar();
}

void Pagina::Mostrar(){
    int m=cuentas;
    if(ramas[0]!=nullptr){
        ramas[0]->Mostrar();
    }
    if (claves[0]!=""&&m>0){
        cout<<claves[0]+":->";
        m--;
    }

    if(ramas[1]!=nullptr){
        ramas[1]->Mostrar();
    }
    if (claves[1]!=""&&m>0){
        cout<<claves[1]+"::->";
        m--;
    }
    if(ramas[2]!=nullptr){
        ramas[2]->Mostrar();
    }
    if (claves[2]!=""&&m>0){
        cout<<claves[2]+":::->";
        m--;
    }
    if(ramas[3]!=nullptr){
        ramas[3]->Mostrar();
    }
    if (claves[3]!=""&&m>0){
        cout<<claves[3]+"::::->";

    }
    if(ramas[4]!=nullptr){
        ramas[4]->Mostrar();
    }
}

void ArbolB::InsertarValor(string pValor){
    bool EA=false;
    string X="0";
    pPagina Xr=nullptr;
    pPagina P=nullptr;
    Empujar(pValor,raiz,EA,X,Xr);
    if (EA){
        P=new Pagina();
        P->cuentas=1;
        P->claves[0]=X;
        P->ramas[0]=raiz;
        P->ramas[1]=Xr;
        raiz=P;
    }
}

void ArbolB::Empujar(string& pValor,pPagina& pRaiz,bool& EA,string& mdna,pPagina& x){
    int k=0;
    bool esta=false;
    if(ArbolVacio(pRaiz)){
        EA=true;
        mdna=pValor;
        x=new Pagina();
    }else{
        BuscarNodo(pValor,pRaiz,esta,k);
        if (esta==true){
        }else{
            Empujar(pValor,pRaiz->ramas[k],EA,mdna,x);
            if(EA){
                if (pRaiz->cuentas<4){
                    EA=false;
                    MeterHoja(mdna,x,pRaiz,k);
                }else{
                    EA=true;
                    DividirNodo(mdna,x,pRaiz,k,mdna,x);
                }
            }
        }
    }
}

void ArbolB::BuscarNodo(string& pValor,pPagina& pRaiz,bool& esta,int& k){
    string codUsuario;
    string::size_type pos = pValor.find(';');
    codUsuario=pValor.substr(pos+1);
    string::size_type pos1=codUsuario.find(';');
    codUsuario=codUsuario.substr(0,pos1);
    if(std::atoi(codUsuario.c_str())<std::atoi(pRaiz->claves[0].c_str())){
        esta=false;
        k=0;
    }else{
        k=pRaiz->cuentas;
        while(std::atoi(codUsuario.c_str())<std::atoi(pRaiz->claves[k-1].c_str())&&k>0){
            k=k-1;
        }
        if (k!=4){
            if (atoi(codUsuario.c_str())==atoi(pRaiz->claves[k-1].c_str())){
                esta=true;
            }
        }
    }

}

void ArbolB::MeterHoja(string& pValor,pPagina& x,pPagina& pRaiz,int& k){
    int i=pRaiz->cuentas-1;
    for(i;k<=i;i--){
        pRaiz->claves[i+1]=pRaiz->claves[i];
        pRaiz->ramas[i+2]=pRaiz->ramas[i+1];
        pRaiz->ramas[i+1]=pRaiz->ramas[i];
    }
    pRaiz->claves[k]=pValor;
    if(i==pRaiz->cuentas-1||i==-1){
       pRaiz->ramas[k+1]=x;
    }else{
       pRaiz->ramas[k]=x;
    }
    pRaiz->cuentas=pRaiz->cuentas+1;
}

void ArbolB::DividirNodo(string& pValor,pPagina Xder,pPagina& pRaiz,int& k,string& mda,pPagina& mder){
    int i;
    int posmda;
    if(k<=2){
        posmda=2;
    }else{
        posmda=3;
    }
    mder= new Pagina();

    for(i=posmda;i<4;i++){
        mder->claves[i-posmda]=pRaiz->claves[i];
        mder->ramas[i+1-posmda]=pRaiz->ramas[i+1];
        mder->ramas[i-posmda]=pRaiz->ramas[i];
    }
    mder->cuentas = 4-posmda;
    pRaiz->cuentas=posmda;

    if (k<=2){
       MeterHoja (pValor,Xder,pRaiz,k);

    }else{
        int y=k-posmda;
        MeterHoja (pValor,Xder,mder,y);
    }
    mda=pRaiz->claves[pRaiz->cuentas-1];
    mder->ramas[0]=pRaiz->ramas[pRaiz->cuentas];
    pRaiz->cuentas=pRaiz->cuentas-1;
}
