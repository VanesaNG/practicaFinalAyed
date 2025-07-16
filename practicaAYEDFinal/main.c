#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "lista.h"

void mostrarEnteros(int num);
void mostrarEnterosDatoPtr(DatoPtr dato);

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

    destruirLista(lista1);

}

void mostrarEnteros(int num){
    printf("\nEl numero es: %d",num);
}

void mostrarEnterosDatoPtr(DatoPtr dato){
    int num = *(int*)dato;
    mostrarEnteros(num);
}
