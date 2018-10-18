
#include <iostream>
#include "clases.h"

using namespace std;

template <typename T >
bool AutomataFinito<T>::buscar_estado(Estado<T> *pt,Estado<T> seBusca)
{
  if(*pt == seBusca) return true;
  if(pt -> transiciones.empty()) return false;
  if(pt -> fueVisitado ) return false;
  else pt -> fueVisitado = true;

  typename::list<Transicion<T> >::iterator it = seBusca.transiciones.begin();
  for(;it != seBusca.transiciones.end();it++){
    //Estado<T> *temporal = &(*it);
    if(buscar_estado(it,seBusca)) return true;
  }
  return false;
}
template <typename T>
void AutomataFinito<T>::visualizar(Estado <T> *caminante)
{
  cout<<*caminante<<endl;
  typename::list<Transicion<T> >::iterator it = caminante.transiciones.begin();
  for(;it != caminante.transiciones.end();it++){
    //Estado<T> *temporal = &(*it);
    (visualizar(it));
  }
}
template <typename T >
bool AutomataFinito<T>::anadir_estado(Estado<T> estadoOrigen,Transicion<T> nuevaTransicion,T objeto)
{
  Estado<T> *nuevo = new Estado<T>(objeto);
  Estado<T> *aux = eInicial;

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
