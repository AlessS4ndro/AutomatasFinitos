#include <iostream>
#include "clases.h"

using namespace std;

template <typename T >
bool AutomataFinitoNoDeterminista<T>::anadir_estado(Estado<T> estadoOrigen,Transicion<T> nuevaTransicion,T objeto)
{
  Estado<T> *nuevo = new Estado<T>(objeto);
  Estado<T> *aux = AutomataFinito<T>::eInicial;

  if(!buscar_estado(aux,*nuevo) ){
    if(buscar_estado(&aux, *estadoOrigen)){
      aux -> transiciones.push_back(nuevaTransicion);
      return true;
    }
    else {
      cout<<"no existe el estado "<<estadoOrigen<<endl;
      return false;
    }
  }
  cout<<"estado a ingresar ya existe"<<endl;
  return false;
}
