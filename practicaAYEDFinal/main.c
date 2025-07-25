#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "lista.h"

void mostrarEnteros(int num);
void mostrarEnterosDatoPtr(DatoPtr dato);
int compararEnterosDatoPtr(DatoPtr dato1, DatoPtr dato2);
int compararEnteros(int n1, int n2);

int main()
{
    /// LISTAS - COLA - PILA - CALLBACKS -

    ListaPtr lista1 = crearLista();
    int n1 = 59, n2 = 35, n3 = 7, n4 = 88, n5 = 13;

    insertarPrimero(lista1, &n1);
    insertarPrimero(lista1, &n2);
    insertarPrimero(lista1, &n3);
    insertarPrimero(lista1, &n4);
    insertarPrimero(lista1, &n5);

    mostrarListaGenerico(lista1, mostrarEnterosDatoPtr);

    int n6 = 47;

    insertarUltimo(lista1, &n6);

    mostrarListaGenerico(lista1, mostrarEnterosDatoPtr);

    int n7 = 40;

    insertarPosicion(lista1, &n7, 5);

    mostrarListaGenerico(lista1, mostrarEnterosDatoPtr);

    ordenarListaBurbuja(lista1, compararEnterosDatoPtr);

    mostrarListaGenerico(lista1, mostrarEnterosDatoPtr);

    destruirLista(lista1);

}

void mostrarEnteros(int num){
    printf("\nEl numero es: %d",num);
}

void mostrarEnterosDatoPtr(DatoPtr dato){
    int num = *(int*)dato;
    mostrarEnteros(num);
}

int compararEnterosDatoPtr(DatoPtr dato1, DatoPtr dato2){
    int n1 = *(int*)dato1;
    int n2 = *(int*)dato2;
    return compararEnteros(n1, n2);
}

int compararEnteros(int n1, int n2){
    if(n1>n2){
        return 1;
    }else{
        return 0;
    }
}
