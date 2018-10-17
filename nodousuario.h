#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <string>
using namespace std;

class NodoUsuario {
   public:
    NodoUsuario(string ciudad, int num, string pNombre, string pTelefono, NodoUsuario *pad=NULL, NodoUsuario *der = NULL, NodoUsuario *izq = NULL, NodoUsuario *sig=NULL, NodoUsuario *ant=NULL):
        padre(pad), Hizq(izq), Hder(der), valor(num), codCiudad(ciudad), nombre(pNombre), telefono(pTelefono), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    string codCiudad;
    string nombre;
    string telefono;
    int FB;
    NodoUsuario *Hizq, *Hder, *siguiente, *anterior, *padre;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num);
};

typedef NodoUsuario *pnodo;
typedef NodoUsuario *pNodoUsuario;

#endif // NODOUSUARIO_H
