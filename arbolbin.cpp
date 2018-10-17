#include "arbolbin.h"
#include "nodobin.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

arbolBin::arbolBin(){
}


void nodoBin::InsertarB(string ciudad){
    nodoBin* y=new nodoBin(ciudad);
    if(y->codCiudad<codCiudad){
        if(Hizq==nullptr){
            Hizq = new nodoBin(ciudad);
        }else{
            Hizq->InsertarB(ciudad);
        }
    }else if(y->codCiudad>codCiudad){
        if(Hder==nullptr){
            Hder = new nodoBin(ciudad);
        }else{
            Hder->InsertarB(ciudad);
        }
    }
}

void arbolBin::leerCiudad(){
    ifstream file;
    string ciudad;
    file.open("Ciudad.txt");
    while(getline(file,ciudad)){
        Insertar(ciudad);
    }
}


void arbolBin::Mostrar(){
    raiz->Mostrar();
}

void nodoBin::Mostrar(){
    cout<<codCiudad<<" "<<nombre <<" -> ";
    if(Hizq!=nullptr){
        Hizq->Mostrar();
    }
    if(Hder!=nullptr){
        Hder->Mostrar();
    }


}


void arbolBin::Insertar(string x){
    if (raiz == nullptr){
        raiz = new nodoBin(x);
    }else{
        raiz->InsertarB(x);
    }
}
