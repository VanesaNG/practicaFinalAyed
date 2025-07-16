#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();
void insertarPrimero(ListaPtr lista, DatoPtr dato);

NodoPtr getPrimeroLista(ListaPtr lista);

void mostrarListaGenerico(ListaPtr lista, void(*mostrar)(DatoPtr));

void destruirLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
