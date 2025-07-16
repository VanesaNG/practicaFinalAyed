#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{
    NodoPtr primero;
};


ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};

void insertarPrimero(ListaPtr lista, DatoPtr dato){
    NodoPtr nodoAInsertar = crearNodo(dato, lista->primero);
    lista->primero = nodoAInsertar;
};

NodoPtr getPrimeroLista(ListaPtr lista){
    return lista->primero;
};

void mostrarListaGenerico(ListaPtr lista, void(*mostrar)(DatoPtr)){
    NodoPtr recorrer = lista->primero;
    printf("La lista es: \n");
    while(recorrer!= NULL){
        (*mostrar)(getDato(recorrer));
        recorrer = getSiguiente(recorrer);
    }
};

void destruirLista(ListaPtr lista){
    NodoPtr recorrer = lista->primero;
    while(recorrer!= NULL){
        NodoPtr nodoAEliminar = recorrer;
        recorrer = getSiguiente(recorrer);
        liberarNodo(nodoAEliminar);
    }
    free(lista);
};
