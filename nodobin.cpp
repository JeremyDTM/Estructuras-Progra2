#include "nodoBin.h"

nodoBin::nodoBin(string v){
    string::size_type pos=v.find(';');
    codCiudad=std::atoi(v.substr(0,pos).c_str());
    nombre=v.substr(pos+1);
    Hizq=nullptr;
    Hder=nullptr;
}
