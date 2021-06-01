#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo *TArbol;
//Implementar una función iterativa que inserte un elemento en un ABB.
void insertaIterativo(TArbol *A,int x);
void muestraArbol(TArbol A);
int main(){
    TArbol A=NULL;
    insertaIterativo(&A,10);
    insertaIterativo(&A,5);
    insertaIterativo(&A,15);
    insertaIterativo(&A,3);
    insertaIterativo(&A,7);
    insertaIterativo(&A,12);
    insertaIterativo(&A,20);
    muestraArbol(A);
    return 0;
}
void insertaIterativo(TArbol *A,int x){
    TArbol ant,act,nuevo;
    ant=NULL; act=*A;

    while (act){
        ant=act;
        if (x>act->dato)
            act=act->der;
        else
            act=act->izq;
    }
    nuevo = (TArbol)malloc(sizeof(nodo));
    nuevo->dato=x;
    nuevo->izq=NULL; nuevo->der=NULL;
    if (ant)
        if (ant->dato>=x)
            ant->izq=nuevo;
        else
            ant->der=nuevo;
    else
        *A=nuevo;
}

void muestraArbol(TArbol A){
    if (A){
        muestraArbol(A->izq);
        printf("%d\n",A->dato);
        muestraArbol(A->der);
    }
}