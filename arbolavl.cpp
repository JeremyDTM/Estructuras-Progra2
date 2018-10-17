#include "arbolavl.h"
#include <iostream>
#include "nodousuario.h"
#include <string>

void AVL::PreordenR(NodoUsuario *R){
    //cout<<endl<<"WWW: "<<R<<"  "<<endl;
    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<"("<<R->FB<<")"<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void AVL::InordenR(NodoUsuario *R){

    if(R==nullptr){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<"("<<R->FB<<")"<<" - ";
        InordenR(R->Hder);
    }
}

void AVL::PostordenR(NodoUsuario *R){

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
    if(raiz==NULL){
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



