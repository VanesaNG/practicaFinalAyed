#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();   ///LISTO
void insertarPrimero(ListaPtr lista, DatoPtr dato);  ///LISTO

NodoPtr getPrimeroLista(ListaPtr lista);   ///LISTO

void mostrarListaGenerico(ListaPtr lista, void(*mostrar)(DatoPtr));   ///LISTO

void destruirLista(ListaPtr lista);   ///LISTO


//////////////

void insertarUltimo(ListaPtr lista, DatoPtr dato);       ///LISTO
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);   ///LISTO


int obtenerPrimero(ListaPtr lista);
int obtenerUltimo(ListaPtr lista); //tarea
int obtenerPosicicon(ListaPtr lista); //tarea

int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarposicicon(ListaPtr lista); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

void ordenarListaBurbuja(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr));//tarea
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, DatoPtr datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, DatoPtr dato);
//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda

#endif // LISTA_H_INCLUDED
