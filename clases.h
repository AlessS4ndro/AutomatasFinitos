#ifndef __CLASES_H__
#define __CLASES_H__
#include <iostream>
#include <list>

using namespace std;

template <typename T = int>
struct Estado;

template <typename T = int>
struct Transicion{
  string etiqueta;
  Estado<T> *destino;
  Transicion(string etiqueta,Estado<T> *destino){
    this -> etiqueta = etiqueta;
    this -> destino = destino;
  }
  ~Transicion(){};
};

template <typename T>
struct Estado{
  typename::list<Transicion<T> >::iterator it;
  list<Transicion<T> > transiciones;
  T objeto;
  bool fueVisitado;
  Estado(T o):objeto(o),fueVisitado(false){}
  ~Estado(){};
  bool anadir_transicion(Transicion<T> nuevaTransicion){
    transiciones.push_back(nuevaTransicion);
  }

};

template <typename T = int>
class AutomataFinito{
  Estado<T> *eInicial;
  list<Estado<T> *> estadosFinales;
  bool buscar_estado(Estado<T> *,Estado<T>);

public:
  AutomataFinito(){}
  AutomataFinito(Estado<T> *eInicial){
    this -> eInicial = eInicial;
  }
  ~AutomataFinito(){};
  bool anadir_estado(Estado<T>,Transicion<T>,T objeto);
  bool eliminar_estado(Estado<T>,Transicion<T>);
  void visualizar(Estado<T> *);

};

template <typename T>
ostream & operator << (ostream &o,Estado<T> objeto)
{
  o<<objeto;
  for(objeto.it = objeto.transiciones.begin() ;objeto.it != objeto.transiciones.end();objeto.it++){
    o<<*(objeto.it).etiqueta<<" -> ";
  }
  return o;
}


#endif
