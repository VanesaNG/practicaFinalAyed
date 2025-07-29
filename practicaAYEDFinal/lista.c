#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{          ///LISTO
    NodoPtr primero;
};

/// CONSTRUCTOR GETTERS Y SETTERS

ListaPtr crearLista(){         ///LISTO
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};

NodoPtr getPrimeroLista(ListaPtr lista){         ///LISTO
    return lista->primero;
};

/// MOSTRAR

void mostrarListaGenerico(ListaPtr lista, void(*mostrar)(DatoPtr)){        ///LISTO
    NodoPtr recorrer = lista->primero;
    printf("La lista es: \n");
    while(recorrer!= NULL){
        (*mostrar)(getDato(recorrer));
        recorrer = getSiguiente(recorrer);
    }
    printf("\n\n");
};


/// INSERTAR: INSERTAR PRIMERO, INSERTAR ULTIMO, INSERTAR POSICION

void insertarPrimero(ListaPtr lista, DatoPtr dato){      ///LISTO
    NodoPtr nodoAInsertar = crearNodo(dato, lista->primero);
    lista->primero = nodoAInsertar;
};

void insertarUltimo(ListaPtr lista, DatoPtr dato){        ///LISTO
    NodoPtr recorrer = lista->primero;
    NodoPtr nodoAInsertar = crearNodo(dato, NULL);
    if(recorrer==NULL){
        lista->primero = nodoAInsertar;
        return;
    }
        while(getSiguiente(recorrer)!=NULL){
            recorrer = getSiguiente(recorrer);
        }
        setSiguiente(recorrer, nodoAInsertar);
};

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){ ///LISTO
    int tam = obtenerTamanio(lista);
    if(posicion<1 || posicion>tam+1){
        return;
    }
    if(posicion==1){
        insertarPrimero(lista, dato);
    }else if(posicion==tam+1){
        insertarUltimo(lista, dato);
    }else{
        NodoPtr primero = lista->primero;
            while(posicion>2){
                primero = getSiguiente(primero);
                posicion--;
            }
        NodoPtr nodoAInsertar = crearNodo(dato, getSiguiente(primero));
        setSiguiente(primero, nodoAInsertar);
    }
};


/// OBTENER TAMAÑO, DESTRUIR LISTA

int obtenerTamanio(ListaPtr lista){ ///LISTO
    int tam = 0;
    NodoPtr primero = lista->primero;
    while(primero != NULL){
        tam++;
        primero = getSiguiente(primero);
    }
    return tam;
}

void destruirLista(ListaPtr lista){         ///LISTO
    NodoPtr recorrer = lista->primero;
    while(recorrer!= NULL){
        NodoPtr nodoAEliminar = recorrer;
        recorrer = getSiguiente(recorrer);
        liberarNodo(nodoAEliminar);
    }
    free(lista);
};

///ORDERNAR

void ordenarListaBurbuja(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr)){         ///LISTO

    DatoPtr aux;
    int tam = obtenerTamanio(lista);
    NodoPtr actual;
    for(int i=0; i<tam-1; i++){
        actual = lista->primero;
        for(int j=0; j<tam-1-i; j++){
            if(comparar(getDato(actual),getDato(getSiguiente(actual)))==1){
                aux = getDato(actual);
                setDato(actual, getDato(getSiguiente(actual)));
                setDato(getSiguiente(actual),aux);
            }
            actual = getSiguiente(actual);
        }
    }

};

void ordenarListaInsercion(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr)){

}

void ordenarListaSeleccion(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr)){

}

int busquedaSecuencial(ListaPtr lista, DatoPtr dato, int(*comparar)(DatoPtr, DatoPtr)){
    NodoPtr actual = lista->primero;
    int encontrado = -1;
    if(actual!=NULL){
        int tam = obtenerTamanio(lista);
            for(int i=1; i<=tam; i++){
                if(comparar(getDato(actual), dato)==1){
                    encontrado = i;
                    return encontrado;
                }
                actual = getSiguiente(actual);
            }
    }
    return encontrado;
}

