#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

class NodoBinario {
   public:

    NodoBinario(int num, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {};
        


    int valor;
    int FB;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior, *padre;

    friend class Pila;
    friend class Binario;

    void asignar(string codciudad, string cel, string nom, string tel);
    
    private:
    string tipo;
    string codigociudad;
    string cedula;
    string nombre;
    string telefono;
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);

void NodoBinario::asignar(string codciudad, string cel, string nom, string tel){
	codigociudad=codciudad;
    cedula=cel;
    nombre=nom;
    telefono=tel;
}

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
    NodoBinario *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;
    
   }
}

pnodo Pila::Pop()
{
    NodoBinario *borrar;
    NodoBinario *salida;
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
    NodoBinario *aux;
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
    NodoBinario *aux = plista;
    while(aux){
        cout<< aux->valor<<" - ";
        aux=aux->siguiente;
    }
}

class AVL{
public:
    pNodoBinario raiz;
	pNodoBinario actual;
    AVL():raiz(NULL){}

    void InsertaNodo(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;
    
    void Borrar(NodoBinario *nodoB, bool);
    void BorrarBalanceado(NodoBinario *r, bool, int eliminar);
    void Equilibrar1(NodoBinario *n, bool);
    void Equilibrar2(NodoBinario *n, bool);
    void Insertar(NodoBinario *r, bool, int x,  pNodoBinario pPadre);
    pNodoBinario RotacionDobleIzquierda(NodoBinario *n1, NodoBinario *n2);
    pNodoBinario RotacionDobleDerecha(NodoBinario *n1, NodoBinario *n2);
    pNodoBinario RotacionSimpleIzquierda(NodoBinario *n1, NodoBinario *n2);
    pNodoBinario RotacionSimpleDerecha(NodoBinario *n1, NodoBinario *n2);


};

void AVL::PreordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    while(p.Vacia()==false || (Act!=NULL)){
        if(Act!=NULL){
            cout<<Act->valor<<" - ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act=p.Pop();
            Act=Act->Hder;
        }
    }
}

void AVL::InordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    bool band=true;
    while(band){
        
        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }
        if(!p.Vacia()){
            Act=p.Pop();
            cout<<Act->valor<<" - ";
            Act=Act->Hder;          
        }
        if(p.Vacia() & Act==NULL){
            break;
        }
    }
}

void AVL::PostordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    Pila p2;
    while(!p.Vacia() || Act!=NULL){
    	cout<<p.Vacia()<<"  "<<Act<<endl;
        if(Act!=NULL){
            p2.Push(new NodoBinario(Act->valor));            
            p.Push(Act);
            Act = Act->Hder;
        }else{            
            Act=p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
    	
        NodoBinario *salida=p2.Pop();
        cout<<salida->valor<<" - ";
    }
}

void PreordenR(NodoBinario *R){
    //cout<<endl<<"WWW: "<<R<<"  "<<endl;
    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<" - ";
        InordenR(R->Hder);
    }
}

void PostordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout<<R->valor<<" - ";
    }
}

void AVL::Borrar(NodoBinario* D, bool Hh)
{
    NodoBinario *q;
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

void AVL::BorrarBalanceado(NodoBinario* raiz, bool Hh, int x)
{
    NodoBinario *q;
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

void AVL::Equilibrar1(NodoBinario* n, bool Hh){
    NodoBinario *n1;
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

void AVL::Equilibrar2(NodoBinario* n, bool Hh){
    NodoBinario *n1;
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

void AVL::Insertar(NodoBinario* ra, bool HhA, int x, NodoBinario* pPadre){
    NodoBinario *n1;
    Hh=HhA;
    if(this->raiz==NULL){
        ra=new NodoBinario(x);
        raiz=ra;
        //cout<<ra->valor<<"q as"<<endl;
        Hh = true;
    }else if(ra==NULL){
    	//cout<<"qaa as"<<endl;
    	if(x>pPadre->valor){
    		ra=new NodoBinario(x);
    		pPadre->Hder=ra;
		}else if(x<pPadre->valor){
    		ra=new NodoBinario(x);
    		pPadre->Hizq=ra;
		}else{
			cout<<endl<<"REPETIDO"<<endl;
		}
    	
    	Hh=true;
	}else{
        //cout<<"q as2"<<endl;
        if(x<ra->valor){
        	//cout<<ra->valor<<"q as3"<<endl;
            Insertar(ra->Hizq, Hh, x,ra);
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
	   	            	if(x>pPadre->valor){
					    	ra=RotacionSimpleIzquierda(ra, n1);
					    	pPadre->Hder=ra;
						}else if(x<pPadre->valor){
				    		ra=RotacionSimpleIzquierda(ra, n1);
				    		pPadre->Hizq=ra;
						}
	                    
	                }else{
	                	if(x>pPadre->valor){
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
                Insertar(ra->Hder, Hh, x,ra);
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
	                        	if(x>pPadre->valor){
						    		ra=RotacionSimpleDerecha(ra, n1);
						    		pPadre->Hder=ra;
								}else if(x<pPadre->valor){
						    		ra=RotacionSimpleDerecha(ra, n1);
						    		pPadre->Hizq=ra;
								}
	                            
	                        }else{
	                        	if(x>pPadre->valor){
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

pNodoBinario AVL::RotacionDobleIzquierda(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    if(this->raiz==n){
		this->raiz=n2;
	}
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

pNodoBinario AVL::RotacionDobleDerecha(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    if(this->raiz==n){
		this->raiz=n2;
	}
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

pNodoBinario AVL::RotacionSimpleDerecha(NodoBinario* n, NodoBinario* n1){
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

pNodoBinario AVL::RotacionSimpleIzquierda(NodoBinario* n, NodoBinario* n1){
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


int main(){

    AVL B;
    B.Insertar(B.raiz, false,6,NULL);
    B.Insertar(B.raiz, B.Hh,2,NULL);
    B.Insertar(B.raiz, B.Hh,7,NULL);
    B.Insertar(B.raiz, B.Hh,9,NULL);
    B.Insertar(B.raiz, B.Hh,8,NULL);
    B.Insertar(B.raiz, B.Hh,4,NULL);
    B.Insertar(B.raiz, B.Hh,5,NULL);
    B.Insertar(B.raiz, B.Hh,1,NULL);
    B.Insertar(B.raiz, B.Hh,3,NULL);
    B.Insertar(B.raiz, B.Hh,10,NULL);
    
	cout<<endl<<"Inorden: "<<endl;
    InordenR(B.raiz);
    cout<<endl<<"Preorden: "<<endl;
    PreordenR(B.raiz);
    cout<<endl<<"Postorden: "<<endl;
    PostordenR(B.raiz);

    
    cin.get();

    return 0;
}

