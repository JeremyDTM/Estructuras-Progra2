#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <math.h>
#include <stdio.h>
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

void PreordenR(NodoUsuario* R);
void InordenR(NodoUsuario* R);
void PostordenR(NodoUsuario* R);



class Pila {
   public:
    Pila() : plista(NULL) {}

    void Push(pnodo);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodo Pop();
    int Size();
    
    pnodo plista;
};

void Pila::Push(pnodo v)
{
   if(Vacia()) {
      plista = v;
   }else{
    NodoUsuario *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;
    
   }
}

pnodo Pila::Pop()
{
    NodoUsuario *borrar;
    NodoUsuario *salida;
    if(Vacia()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plista;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(Size()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plista;        
        plista = NULL;
    }
    }    
    return salida;
}

int Pila::Size(){
    while(plista && plista->anterior) plista = plista->anterior;
    int cont=0;
    NodoUsuario *aux;
    aux=plista;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void Pila::Mostrar(){
    if(Vacia()){
        cout<<"Vacia";
    }
    NodoUsuario *aux = plista;
    while(aux){
        cout<< aux->valor<<" - ";
        aux=aux->siguiente;
    }
}

class AVL{
public:
    pNodoUsuario raiz;
	pNodoUsuario actual;
    AVL():raiz(NULL){}

    void InsertaNodo(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;
    
    void Borrar(NodoUsuario *nodoB, bool);
    void BorrarBalanceado(NodoUsuario *r, bool, int eliminar);
    void Equilibrar1(NodoUsuario *n, bool);
    void Equilibrar2(NodoUsuario *n, bool);
    void Insertar(NodoUsuario *r, bool, string ciudad, int x, string nombre, string telefono, pNodoUsuario pPadre);
    pNodoUsuario RotacionDobleIzquierda(NodoUsuario *n1, NodoUsuario *n2);
    pNodoUsuario RotacionDobleDerecha(NodoUsuario *n1, NodoUsuario *n2);
    pNodoUsuario RotacionSimpleIzquierda(NodoUsuario *n1, NodoUsuario *n2);
    pNodoUsuario RotacionSimpleDerecha(NodoUsuario *n1, NodoUsuario *n2);


};

void PreordenR(NodoUsuario *R){
    //cout<<endl<<"WWW: "<<R<<"  "<<endl;
    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<"("<<R->FB<<")"<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoUsuario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<"("<<R->FB<<")"<<" - ";
        InordenR(R->Hder);
    }
}

void PostordenR(NodoUsuario *R){

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout<<R->valor<<"("<<R->FB<<")"<<" - ";
    }
}

void AVL::Borrar(NodoUsuario* D, bool Hh)
{
    NodoUsuario *q;
    if(D->Hder !=NULL){
        Borrar(D->Hder, Hh);
        if(Hh){
            Equilibrar2(D, Hh);
        }else{
            q->valor=D->valor;
            q=D;
            D=D->Hizq;
            Hh = true;
        }
    }
}

void AVL::BorrarBalanceado(NodoUsuario* raiz, bool Hh, int x)
{
    NodoUsuario *q;
    if(raiz!=NULL){
        if(x<raiz->valor){
            BorrarBalanceado(raiz->Hizq, Hh, x);
            if(Hh){
                Equilibrar1(raiz, Hh);
            }
        }else{
            if(x>raiz->valor){
                BorrarBalanceado(raiz->Hder, Hh, x);
                if(Hh){
                    Equilibrar2(raiz, Hh);
                }
            }else{
                q=raiz;
            }
        }

                if(q->Hder==NULL){
                    raiz=q->Hizq;
                    Hh=true;
                }else{
                    if(q->Hizq==NULL){
                        raiz=q->Hder;
                        Hh = true;
                    }else{
                        Borrar(q->Hizq, Hh);
                    }
                    if(Hh){
                        Equilibrar1(raiz, Hh);
                    }
                }
            }
}

void AVL::Equilibrar1(NodoUsuario* n, bool Hh){
    NodoUsuario *n1;
    switch (n->FB){
        case -1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case 1: n1 = n->Hder;
        if(n1->FB>=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleDerecha(n, n1);
            }else{
                RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void AVL::Equilibrar2(NodoUsuario* n, bool Hh){
    NodoUsuario *n1;
    switch (n->FB){
        case 1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case -1: n1 = n->Hizq;
        if(n1->FB<=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleIzquierda(n, n1);
            }else{
                RotacionDobleIzquierda(n, n1);
            }
        }
    }
}

void AVL::Insertar(NodoUsuario* ra, bool HhA, string ciudad, int x, string nombre, string telefono, NodoUsuario* pPadre){
    NodoUsuario *n1;
    Hh=HhA;
    if(this->raiz==NULL){
        ra=new NodoUsuario(ciudad, x, nombre, telefono);
        raiz=ra;
        //cout<<ra->valor<<"q as"<<endl;
        Hh = true;
    }else if(ra==NULL){
    	//cout<<"qaa as"<<endl;
    	if(x>pPadre->valor){
    		ra=new NodoUsuario(ciudad, x, nombre, telefono);
    		pPadre->Hder=ra;
		}else if(x<pPadre->valor){
    		ra=new NodoUsuario(ciudad, x, nombre, telefono);
    		pPadre->Hizq=ra;
		}else{
			cout<<endl<<"REPETIDO"<<endl;
		}
    	
    	Hh=true;
	}else{
        //cout<<"q as2"<<endl;
        if(x<ra->valor){
        	//cout<<ra->valor<<"q as3"<<endl;
            Insertar(ra->Hizq, Hh, ciudad, x, nombre, telefono,ra);
			//cout<<ra->valor<<"q as4"<<endl;
	        if(Hh){
	            switch(ra->FB){
	                case 1: ra->FB=0;
	                Hh = false;
	                break;
	                case 0: ra->FB  = -1;
	                break;
	                case -1: n1=ra->Hizq;
	                if(n1->FB==-1){
	                	if(raiz==ra){
	                		ra=RotacionSimpleIzquierda(ra, n1);
	   	            	}else if(x>pPadre->valor){
					    	ra=RotacionSimpleIzquierda(ra, n1);
					    	pPadre->Hder=ra;
						}else if(x<pPadre->valor){
				    		ra=RotacionSimpleIzquierda(ra, n1);
				    		pPadre->Hizq=ra;
						}
	                    
	                }else{
	                	if(raiz==ra){
	                		ra=RotacionSimpleIzquierda(ra, n1);
	   	            	}else if(x>pPadre->valor){
						    	ra=RotacionDobleIzquierda(ra,n1);
						    	pPadre->Hder=ra;
						}else if(x<pPadre->valor){
				    		ra=RotacionDobleIzquierda(ra,n1);
				    		pPadre->Hizq=ra;
						}
	                    
	                }
	                Hh = false;
	                break;
	            }
	        }
        }else{
        	//cout<<ra->valor<<"q as3"<<endl;
            if(x>ra->valor){
            	//cout<<ra->valor<<"q as3.1"<<endl;
                Insertar(ra->Hder, Hh, ciudad, x, nombre, telefono,ra);
                //cout<<ra->valor<<"q as4"<<endl;
				//cout<<endl<<"LW ";
				//cout<<ra->FB<<endl;
                if(Hh){
                	
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:
							n1=ra->Hder;
	                        if(n1->FB==1){
	                        	if(raiz==ra){
	                				ra=RotacionSimpleDerecha(ra, n1);
	   	            			}else if(x>pPadre->valor){
						    		ra=RotacionSimpleDerecha(ra, n1);
						    		pPadre->Hder=ra;
								}else if(x<pPadre->valor){
						    		ra=RotacionSimpleDerecha(ra, n1);
						    		pPadre->Hizq=ra;
								}
	                            
	                        }else{
	                        	if(raiz==ra){
	                				ra=RotacionSimpleDerecha(ra, n1);
	   	            			}else if(x>pPadre->valor){
						    		ra=RotacionDobleDerecha(ra, n1);
						    		pPadre->Hder=ra;
								}else if(x<pPadre->valor){
						    		ra=RotacionDobleDerecha(ra, n1);
						    		pPadre->Hizq=ra;
								}
	                            
	                        }
	                        Hh=false;
                        break;
                    }
                }
            }
        }
    }
}

pNodoUsuario AVL::RotacionDobleIzquierda(NodoUsuario* n, NodoUsuario* n1){
    NodoUsuario *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
    return n;
}

pNodoUsuario AVL::RotacionDobleDerecha(NodoUsuario* n, NodoUsuario* n1){
    NodoUsuario *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
    return n;
}

pNodoUsuario AVL::RotacionSimpleDerecha(NodoUsuario* n, NodoUsuario* n1){
	if(this->raiz==n){
		this->raiz=n1;
	}
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
    return n;
}

pNodoUsuario AVL::RotacionSimpleIzquierda(NodoUsuario* n, NodoUsuario* n1){
	if(this->raiz==n){
		this->raiz=n1;
	}
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
    return n;
}

cargarArch(ifstream& arch){	
	AVL B;
	B.Hh=false;
	char char1[128];
	int cont=0;
	int cont2=0;
	int conta=0;
	while(!arch.eof()){
		arch.getline(char1,sizeof(char1));
		cont=0;
		char char2[128]={0};
		char char3[128]={0};
		char char4[128]={0};
		char char5[128]={0};
		char char6[128]={0};
		while(char1[cont]!='\0'){
				while(char1[cont]!=';' and char1[cont]!='\0'){
					char2[cont2]=char1[cont];
					cont++;
					cont2++;
				}
				cont2=0;
				cont++;
				while(char1[cont]!=';' and char1[cont]!='\0'){
					char3[cont2]=char1[cont];
					cont++;
					cont2++;
				}
				cont2=0;
				cont++;
				while(char1[cont]!=';' and char1[cont]!='\0'){
					char4[cont2]=char1[cont];
					cont++;
					cont2++;
				}
				cont2=0;
				cont++;
				while(char1[cont]!=';' and char1[cont]!='\0'){
					char5[cont2]=char1[cont];
					cont++;
					cont2++;
				}
				cont2=0;
				cont++;
				while(char1[cont]!=';' and char1[cont]!='\0'){
					char6[cont2]=char1[cont];
					cont++;
					cont2++;
				}
				cont2=0;
				cont++;
				//cout<<endl<<char2<<" | "<<char3<<" | "<<char4<<" | "<<char5<<" | "<<char6<<" | "<<char1<<endl;
				if(char6[0]=='3'){
					B.Insertar(B.raiz, false,char2,atoi(char3),char4,char5,NULL);
				}
				
			}
		
		while(conta<128){
			char1[conta]=0;
			conta++;
		}
		conta=0;	
	}
	PreordenR(B.raiz);
	arch.close();
}

int main(){
	ifstream arch("Usuarios.txt");
	cargarArch(arch);
}
