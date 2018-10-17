#include <iostream>
#include "arbolb.h"
#include "pagina.h"
#include "arbolbin.h"
#include <fstream>
#include <string>
#include "listasimple.h"

using namespace std;



void menu(listaSimple& lista,arbolBin& arbolBin){
    arbolBin.leerCiudad();
    lista.users(arbolBin);
    lista.Mostrar();
}

int main(){
    ArbolB* arbolB=new ArbolB();
    AVL* arbolAVL=new AVL();
    listaSimple listaUsuarios;
    listaUsuarios.Insertar(0,arbolB);
    listaUsuarios.Insertar(1,arbolB);
    listaUsuarios.Insertar(2,arbolB);
    listaUsuarios.Insertar(3,arbolAVL);
    arbolBin arbBin;
    menu(listaUsuarios,arbBin);
    cout<<endl;
    cout<<"arbol binario: ";
    arbBin.Mostrar();

    return 0;
}
