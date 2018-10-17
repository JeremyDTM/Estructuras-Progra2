#include "listasimple.h"
#include "arbolb.h"
#include "arbolbin.h"
#include <fstream>

listaSimple::listaSimple(){
}


void listaSimple::Insertar(int num, ArbolB* arbolB){
    if (primero==nullptr){
        primero=new nodoSimple(num,arbolB);
        primero->siguiente=primero;
        primero->anterior=primero;
    }else{
        nodoSimple* aux=new nodoSimple(num,arbolB);
        nodoSimple* temp=primero;
        if (num<primero->valor){
            aux->anterior=primero->anterior;
            aux->siguiente=primero;
            primero->anterior=aux;
            primero=aux;
        }
        while(temp->valor<num&&temp->siguiente!=primero){
            temp=temp->siguiente;
        }
        aux->anterior=temp;
        aux->siguiente=temp->siguiente;
        temp->siguiente=aux;
    }

}

void listaSimple::Insertar(int num, AVL* arbolAVL){
    if (primero==nullptr){
        primero=new nodoSimple(num,arbolAVL);
        primero->siguiente=primero;
        primero->anterior=primero;
    }else{
        nodoSimple* aux=new nodoSimple(num,arbolAVL);
        nodoSimple* temp=primero;
        if (num<primero->valor){
            aux->anterior=primero->anterior;
            aux->siguiente=primero;
            primero->anterior=aux;
            primero=aux;
        }
        while(temp->valor<num&&temp->siguiente!=primero){
            temp=temp->siguiente;
        }
        aux->anterior=temp;
        aux->siguiente=temp->siguiente;
        temp->siguiente=aux;
    }

}

void listaSimple::Mostrar(){
    primero->abajo->MostrarRaiz();
}

void listaSimple::users(arbolBin arbolBin){
    ifstream file;
    string usuario;
    file.open("Usuarios.txt");
    while(getline(file,usuario)){
        string::size_type pos = usuario.find(';');
        string codCiudad=usuario.substr(0,pos);
        int cod=std::atoi(codCiudad.c_str());
        string tipoX=usuario.substr(pos+1);
        for(int i=0;i<4;i++){
            pos = tipoX.find(';');
            tipoX=tipoX.substr(pos+1);
        }
        int tipo=std::atoi(tipoX.c_str());
        nodoSimple *aux=primero;
        if (tipo!=3){
            while(aux->valor!=tipo){
                aux=aux->siguiente;
            }
            aux->abajo->InsertarValor(usuario);
        }else{
            while(aux->valor!=tipo){
                aux=aux->siguiente;
            }
        }
    }
}
